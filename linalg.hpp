#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>


namespace Compute{

template<typename T>
class Matrix {
    private:
        int rows;
        int cols;
        std::vector<std::vector<T>> data;

    public:
        Matrix() = delete;
        Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<T>(c)) {}
        Matrix(int s): rows(s), cols(s), data(s, std::vector<T>(s)) {}
        
        void print(){
            for(auto& v: data){
                for(auto& c: v){
                    std::cout << c << " ";
                }
                std::cout << std::endl;
            }
        }
       
        void fill(const T& value){
            for(auto& row: data){
                std::fill(row.begin(), row.end(), value);
            }
        }

        void set(int r, int c, const T& val) {
            data[r][c] = val;
        }

        T det(){
            if(rows != cols){
                throw std::runtime_error("Matrix is not invertible");
            }
            T determinant = T();
            int n = rows;
            Matrix& m = *this;
            if(n == 1){
                return m[0][0];
            }

            if(n == 2){
                return m[0][0] * m[1][1] - m[0][1] * m[1][0];
            }
            int sign = 1;
            for(int i = 0; i < cols; i++){
                
                Matrix cofactor = Matrix(rows-1, cols-1);
                for(int j=1; j < rows; j++){
                    int l;
                    for(int k=0; k < cols; k++){
                        if(i == k) continue;
                        if(k>i) l = k-1;
                        else l = k;
                        cofactor[j-1][l] = m[j][k];
                    }
                    

                }
                determinant += sign * m[0][i] * cofactor.det();
                sign *= -1;

            }
            return determinant;
            
        }
        

        const std::vector<T>& operator[](int index) const {
            return data[index];
        }

        std::vector<T>& operator[](int index){
            return data[index];
        }

        Matrix operator+(const Matrix& m){
            Matrix<T> out(rows, cols);
            for(int i = 0; i < rows; i++){
                for(int j=0; j < cols; j++){
                    out[i][j] = data[i][j] + m[i][j];
                }
            }
            return out;
        }

        Matrix operator-(const Matrix& m){
            return *this + (-1 * m);
        }

        void exp(int value){
            Matrix& out = *this;
            for(auto& row: out.data){
                for(auto& elem: row){
                    elem = pow(elem, value);
                }
            }
        }

        Matrix operator*(const T& value) const{
            Matrix out = *this;
            for(auto& row : out.data){
                for(auto& elem: row){
                    elem*= value;
                }
            }
            return out;
        }

        friend std::ostream& operator<<(std::ostream& stream, const Matrix& m){
            for(auto& row: m.data){
                for(auto& elem: row){
                    stream << elem << " ";
                }
                stream << std::endl;
            }
            return stream;
        }

        friend Matrix operator*(const T& value,const Matrix& m){
            return m * value;
        }
};


}
