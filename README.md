The release in the Right-> has all the zip of all codes and datasets needed for practical
Dataset being very large i had to make a release as zip 

HPC Code details :-

sudo apt install libomp-dev

To run OpenMp codes run following commands on terminal-

gcc -o a -fopenmp file.cpp OR g++ -o a -fopenmp file.cpp

./a

To run CUDA codes run following commands on terminal-

nvcc -o a.out file.cu OR nvcc -o a file.cu

./a.out OR ./a
