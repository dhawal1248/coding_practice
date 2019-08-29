filename=$1".cpp"
exec_filename=$1

dir_file=$(ls | grep $filename | tail -n 1)

[ "$dir_file" = "$filename" ] && file_found=1 || file_found=0

if [ $file_found -eq 0 ]
then
    printf "File $filename Not Found\n"
else
    if g++ -g -std=c++11 $filename -o $exec_filename;then
        printf "Compilation Done\n"
        printf "Running "$exec_filename
        printf "\n\n"
        v=$(./$exec_filename)
        echo $v
    else
        printf "Compilation Error"
    fi
fi    
