#include <iostream>
#include <vector>


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

        Matrix operator*(const T& value) const{
            Matrix out = *this;
            for(auto& row : out.data){
                for(auto& elem: row){
                    elem*= value;
                }
            }
            return out;
        }

        friend Matrix operator*(const T& value,const Matrix& m){
            return m * value;
        }
};


}
