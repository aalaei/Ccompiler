RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color
printf ${RED}"clean...\n"${BLUE}
make clean
printf ${NC}"make...\n"${GREEN}
make
printf ${NC}
mkdir build
cd preProcessor
./auto.sh
cp pre ../build/
cd ..
cp compiler build/
cd build/
#printf ${GREEN}"\tprocessing:\n"${NC}
#./pre test.c ./output_pre.c NoDef
printf ${GREEN}"\tcompiling:\n"${NC}
./compiler test.c --show --pre
printf ${CYAN}"done!"${NC}
printf "\n"