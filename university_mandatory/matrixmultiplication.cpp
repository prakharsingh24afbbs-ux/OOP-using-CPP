#include <iostream>

class Matrix{
    int rows, cols;
    int** data;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for(int i=0; i<rows; i++){
            data[i] = new int[cols];
        }
        for(int j=0; j<rows; j++){
            for(int k=0; k<cols; k++){
                data[j][k]=0;
            }
        }
        std::cout<<"Matrix of "<<rows<<" rows and "<<cols<<" columns allocated and initialized to zero."<<std::endl;
    }
    ~Matrix(){
        for(int i=0; i<rows; i++){
            delete[] data[i];
        }
        delete[] data;
        std::cout<<"Matrix space cleanly deallocated."<<std::endl;
    }
    Matrix(const Matrix& src){
        rows=src.rows;
        cols=src.cols;
        data=new int*[rows];
        for(int i=0; i<rows; i++){
            data[i]=new int[cols];
        }
        for(int j=0; j<rows; j++){
            for(int k=0; k<cols; k++){
                data[j][k]=src.data[j][k];
            }
        }
        std::cout<<"Deep copy completed successfully."<<std::endl;
    }
    void initialize(){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                std::cout<<"Enter value of row "<<i<<", column "<<j<<": ";
                std::cin>>data[i][j];
            }
        }
    }
    void print(){
        for(int i=0; i< rows; i++){
            for(int j=0; j<cols; j++){
                std::cout<<data[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
    Matrix multiply(const Matrix& m){
        if(cols!=m.rows){
            std::cout<<"Matrix multiplication not possible."<<std::endl;
            return Matrix(0,0);
        }
        Matrix result(rows, m.cols);
        for(int i=0; i<rows; i++){
            for(int j=0; j<m.cols; j++){
                result.data[i][j]=0;
                for(int k=0; k<cols; k++){
                    result.data[i][j]+=data[i][k]*m.data[k][j];
                }
            }
        }
        return result;
    }
};

int main(){
    int r1, c1, r2, c2;
    std::cout<<"Enter number of rows and columns for first matrix:"<<std::endl;
    std::cin>>r1>>c1;
    std::cout<<"Enter number of rows and columns for second matrix:"<<std::endl;
    std::cin>>r2>>c2;
    Matrix m1(r1, c1), m2(r2, c2);
    m1.initialize();
    m2.initialize();
    std::cout<<"First matrix:"<<std::endl;
    m1.print();
    std::cout<<"Second matrix:"<<std::endl;
    m2.print();
    Matrix m3 = m1.multiply(m2); //copy created when m2 is passed by value to multiply function
    std::cout<<"Resultant matrix after multiplication:"<<std::endl;
    m3.print();

    return 0;
}