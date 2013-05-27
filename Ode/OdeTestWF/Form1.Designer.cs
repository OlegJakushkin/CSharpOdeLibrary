namespace OdeTestWF
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.zg1 = new ZedGraph.ZedGraphControl();
            this.StepperBox = new System.Windows.Forms.ComboBox();
            this.IntegrateFunctionBox = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.FromGUI = new System.Windows.Forms.NumericUpDown();
            this.ToGUI = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.StepGUI = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.FromGUI)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ToGUI)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.StepGUI)).BeginInit();
            this.SuspendLayout();
            // 
            // zg1
            // 
            this.zg1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.zg1.EditButtons = System.Windows.Forms.MouseButtons.Left;
            this.zg1.IsAntiAlias = true;
            this.zg1.IsAutoScrollRange = true;
            this.zg1.IsSynchronizeXAxes = true;
            this.zg1.IsSynchronizeYAxes = true;
            this.zg1.Location = new System.Drawing.Point(12, 12);
            this.zg1.MinimumSize = new System.Drawing.Size(300, 300);
            this.zg1.Name = "zg1";
            this.zg1.PanButtons2 = System.Windows.Forms.MouseButtons.None;
            this.zg1.PanModifierKeys = System.Windows.Forms.Keys.None;
            this.zg1.ScrollGrace = 0D;
            this.zg1.ScrollMaxX = 0D;
            this.zg1.ScrollMaxY = 0D;
            this.zg1.ScrollMaxY2 = 0D;
            this.zg1.ScrollMinX = 0D;
            this.zg1.ScrollMinY = 0D;
            this.zg1.ScrollMinY2 = 0D;
            this.zg1.Size = new System.Drawing.Size(550, 424);
            this.zg1.TabIndex = 19;
            this.zg1.ZoomButtons = System.Windows.Forms.MouseButtons.Middle;
            // 
            // StepperBox
            // 
            this.StepperBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.StepperBox.FormattingEnabled = true;
            this.StepperBox.Location = new System.Drawing.Point(93, 487);
            this.StepperBox.Name = "StepperBox";
            this.StepperBox.Size = new System.Drawing.Size(121, 21);
            this.StepperBox.TabIndex = 20;
            // 
            // IntegrateFunctionBox
            // 
            this.IntegrateFunctionBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.IntegrateFunctionBox.FormattingEnabled = true;
            this.IntegrateFunctionBox.Location = new System.Drawing.Point(311, 487);
            this.IntegrateFunctionBox.Name = "IntegrateFunctionBox";
            this.IntegrateFunctionBox.Size = new System.Drawing.Size(121, 21);
            this.IntegrateFunctionBox.TabIndex = 21;
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(43, 490);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 13);
            this.label1.TabIndex = 22;
            this.label1.Text = "Stepper";
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(220, 491);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(90, 13);
            this.label2.TabIndex = 23;
            this.label2.Text = "IntegrateFunction";
            // 
            // button1
            // 
            this.button1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button1.Location = new System.Drawing.Point(439, 486);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(92, 23);
            this.button1.TabIndex = 24;
            this.button1.Text = "Run";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // FromGUI
            // 
            this.FromGUI.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.FromGUI.DecimalPlaces = 5;
            this.FromGUI.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.FromGUI.Location = new System.Drawing.Point(93, 461);
            this.FromGUI.Maximum = new decimal(new int[] {
            10000000,
            0,
            0,
            0});
            this.FromGUI.Name = "FromGUI";
            this.FromGUI.Size = new System.Drawing.Size(89, 20);
            this.FromGUI.TabIndex = 25;
            // 
            // ToGUI
            // 
            this.ToGUI.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.ToGUI.DecimalPlaces = 5;
            this.ToGUI.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.ToGUI.Location = new System.Drawing.Point(223, 462);
            this.ToGUI.Maximum = new decimal(new int[] {
            10000000,
            0,
            0,
            0});
            this.ToGUI.Name = "ToGUI";
            this.ToGUI.Size = new System.Drawing.Size(81, 20);
            this.ToGUI.TabIndex = 26;
            this.ToGUI.Value = new decimal(new int[] {
            25,
            0,
            0,
            0});
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(197, 464);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(20, 13);
            this.label3.TabIndex = 27;
            this.label3.Text = "To";
            // 
            // label4
            // 
            this.label4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(43, 461);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(30, 13);
            this.label4.TabIndex = 28;
            this.label4.Text = "From";
            // 
            // label5
            // 
            this.label5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(325, 464);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(29, 13);
            this.label5.TabIndex = 30;
            this.label5.Text = "Step";
            // 
            // StepGUI
            // 
            this.StepGUI.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.StepGUI.DecimalPlaces = 6;
            this.StepGUI.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.StepGUI.Location = new System.Drawing.Point(362, 462);
            this.StepGUI.Maximum = new decimal(new int[] {
            10000000,
            0,
            0,
            0});
            this.StepGUI.Name = "StepGUI";
            this.StepGUI.Size = new System.Drawing.Size(81, 20);
            this.StepGUI.TabIndex = 29;
            this.StepGUI.Value = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(574, 523);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.StepGUI);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.ToGUI);
            this.Controls.Add(this.FromGUI);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.IntegrateFunctionBox);
            this.Controls.Add(this.StepperBox);
            this.Controls.Add(this.zg1);
            this.Name = "Form1";
            this.Text = "ODE Solution Demo";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.FromGUI)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ToGUI)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.StepGUI)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private ZedGraph.ZedGraphControl zg1;
        private System.Windows.Forms.ComboBox StepperBox;
        private System.Windows.Forms.ComboBox IntegrateFunctionBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.NumericUpDown FromGUI;
        private System.Windows.Forms.NumericUpDown ToGUI;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.NumericUpDown StepGUI;
    }
}

