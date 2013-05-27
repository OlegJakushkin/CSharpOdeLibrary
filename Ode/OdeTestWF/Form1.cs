﻿using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using OdeLibrary;

namespace OdeTestWF
{
    public partial class Form1 : Form
    {
        private LambdaOde _lorenz;

        private readonly List<double> _columns = new List<double>();
        private readonly List<double> _rows = new List<double>();
        private readonly Solver _solver = new Solver();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Prepare UI
            var graph = zg1;
            var graphPane = zg1.GraphPane;
            graphPane.Title.Text = "Graph";
            graphPane.XAxis.Title.Text = "x2";
            graphPane.YAxis.Title.Text = "x0";
            graph.IsShowPointValues = true;
            StepperBox.DataSource = Enum.GetNames(typeof (Stepper));
            StepperBox.DropDownStyle = ComboBoxStyle.DropDownList;
            IntegrateFunctionBox.DataSource = Enum.GetNames(typeof (IntegrateFunction));
            IntegrateFunctionBox.DropDownStyle = ComboBoxStyle.DropDownList;

            //library class provides a simple to use Lambda API for ODE system defenition (example of lorenz, 50 steps)
            _lorenz = new LambdaOde
            {
                InitialConditions = new StateType(new[] { 10, 1.0, 1.0 }),
                OdeObserver =
                (x, t) =>
                {
                    _columns.Add(x[0]);
                    _rows.Add(x[2]);
                },
                OdeSystem =
                (x, dxdt, t) =>
                {
                    const double sigma = 10.0;
                    const double r = 28.0;
                    const double b = 8.0 / 3.0;
                    dxdt[0] = sigma * (x[1] - x[0]);
                    dxdt[1] = r * x[0] - x[1] - x[0] * x[2];
                    dxdt[2] = -b * x[2] + x[0] * x[1];
                }

            };
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //library uses one solver type (more will come if there will be demand): dense output stepper based on runge_kutta_dopri5 with standard error bounds 10^(-6) for the steps.
            try
            {
                _columns.Clear();
                _rows.Clear();

                var stepper = (Stepper) Enum.Parse(typeof (Stepper), StepperBox.Text);
                var integrateFunction =
                    (IntegrateFunction) Enum.Parse(typeof (IntegrateFunction), IntegrateFunctionBox.Text);

                _lorenz.From = (double)FromGUI.Value;
                _lorenz.To = (double)ToGUI.Value;
                _lorenz.Step = (double)StepGUI.Value;

                // And all we need to solve it:
                _solver.Solve(_lorenz, integrateFunction, stepper);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                return;
            }
            //Draw ZedGraph
            var graph = zg1;
            var graphPane = zg1.GraphPane;
            graphPane.CurveList.Clear();
            graphPane.GraphObjList.Clear();
            graphPane.AddCurve(
                                     "Lorenz",
                                     _rows.ToArray(),
                                     _columns.ToArray(),
                                     Color.CornflowerBlue);

            graph.AxisChange();
            graph.Invalidate();
            graph.Refresh();
        }
    }
}
