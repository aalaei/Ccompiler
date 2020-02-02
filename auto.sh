make clean
make
cd preProcessor
./auto.sh
cp pre ../
cd ..
echo "processing:"
./pre test.c ./output_pre.c NoDef

./compiler output_pre.c