namespace std {
 %typemap(csclassmodifiers) complex "public partial class";
}

%{
#include <complex>
%}

namespace std {
    template<class T>
    class complex {
    public:
        complex(T r, T i);
        complex(const complex<T> & other);

        T imag();

        T real();

        %rename(Add) operator+=;
        %rename(Substract) operator-=;
        %rename(Multiply) operator*=;
        %rename(Divide) operator/=;

	%extend {
		complex<T>& Multiply(T r){
			return self->operator*= ( r );
		}
		
	}

        complex<T>& operator+= (const complex<T>& rhs);
        complex<T>& operator-= (const complex<T>& rhs);
        complex<T>& operator*= (const complex<T>& rhs);
        complex<T>& operator/= (const complex<T>& rhs);
    };
}

%template(Complex) std::complex<double>;

%{
typedef std::complex<double> Complex ;
%}