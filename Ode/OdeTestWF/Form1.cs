using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using OdeLibrary;

namespace OdeTestWF
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //library uses one solver type (more will come if there will be demand): dense output stepper based on runge_kutta_dopri5 with standard error bounds 10^(-6) for the steps.
            var solver = new Solver();

            var columns = new List<double>();
            var rows = new List<double>();


            //library class provides a simple to use Lambda API for ODE system defenition (example of lorenz, 50 steps)
            var lorenz = new LambdaOde
            {
                From = 0,
                To = 25,
                Step = 0.1,
                InitialConditions = new StateType(new[] { 10, 1.0, 1.0 }),
                OdeObserver = 
                (x, t) => {
                    columns.Add(x[0]);
                    rows.Add(x[2]);
                },
                OdeSystem = 
                (x, dxdt, t) => {
                    const double sigma = 10.0;
                    const double r = 28.0;
                    const double b = 8.0 / 3.0;
                    dxdt[0] = sigma * (x[1] - x[0]);
                    dxdt[1] = r * x[0] - x[1] - x[0] * x[2];
                    dxdt[2] = -b * x[2] + x[0] * x[1];
                }

            };

            // And all we need to solve it:
            solver.Solve(lorenz);

            //Draw ZedGraph
            var graph = zg1;
            var graphPane = zg1.GraphPane;
            graphPane.Title.Text = "Graph";
            graphPane.XAxis.Title.Text = "x2";
            graphPane.YAxis.Title.Text = "x0";
            graph.IsShowPointValues = true;

            graphPane.AddCurve(
                                     "Lorenz",
                                     rows.ToArray(),
                                     columns.ToArray(),
                                     Color.CornflowerBlue);

            graph.AxisChange();
            graph.Invalidate();
            graph.Refresh();
        }
    }
}
