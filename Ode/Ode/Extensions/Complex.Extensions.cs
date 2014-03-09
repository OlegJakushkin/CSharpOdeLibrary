using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

// ReSharper disable once CheckNamespace
namespace OdeLibrary
{
    public partial class Complex {

        

        public static Complex operator +(Complex c1, Complex c2) {
              var result = new Complex(c1);
              result.Add(c2);
              return result;
          }
          public static Complex operator -(Complex c1, Complex c2) {
              var result = new Complex(c1);
              result.Substract(c2);
              return result;
          }

          public static Complex operator *(Complex c1, Complex c2) {
              var result = new Complex(c1);
              result.Multiply(c2);
              return result;
          }

          public static Complex operator *(Complex c1, double c2)
          {
              var result = new Complex(c1);
              result.Multiply(c2);
              return result;
          }

          public static Complex operator /(Complex c1, Complex c2) {
              var result = new Complex(c1);
              result.Divide(c2);
              return result;
        }

        public override string ToString()
        {
            return string.Format("{{{0}; {1}}}", real(), imag());
        }

        public double Norm()
        {
            return Math.Pow(real(), 2) + Math.Pow(imag(), 2);
        }
    }
}
