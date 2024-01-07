export PROJECT=$1

export BuildDir=.build
export OutDir=.out

# export ENGINE=SopelGE

export Red=1
export Green=2
export Blue=6
export White=7

mkdir -p $BuildDir
cd $BuildDir

tput setaf $Blue; #Color Blue 
printf "========= Start generating project =========\n"
tput setaf $White; #Color White
cmake -G "MSYS Makefiles" ..
tput setaf $Blue; #Color Blue 
printf "========== Start building project ==========\n" 
tput setaf $White; #Color White
make $PROJECT
result=$?

if [[ ${result} -gt 0 ]]
then 
    tput setaf $Red;
    printf "=============== Build faild  ===============\n" 
else 
    tput setaf $Green;
    printf "=============== Build success ==============\n" 
    tput setaf $White;
    printf "Deplaying files ... "
    cd ..
    mkdir -p $OutDir
    cp $BuildDir/$PROJECT.exe $OutDir/

    printf "Done\n"
    tput setaf $Green;
    printf "================ Run project ===============\n" 
    cd $OutDir
    tput setaf $White;
    printf "\n"
    ./$PROJECT.exe
    printf "\n"
    tput setaf $Green; 
    printf "================ Project End ===============\n"
    tput setaf $White;
fi