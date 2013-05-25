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
            this.zg1.Location = new System.Drawing.Point(43, 12);
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
            this.zg1.Size = new System.Drawing.Size(488, 461);
            this.zg1.TabIndex = 19;
            this.zg1.ZoomButtons = System.Windows.Forms.MouseButtons.Middle;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(574, 523);
            this.Controls.Add(this.zg1);
            this.Name = "Form1";
            this.Text = "ODE Solution Demo";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private ZedGraph.ZedGraphControl zg1;
    }
}

