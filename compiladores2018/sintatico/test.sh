for file in entradas/*;
do
  for subfile in ${file}/*; do
    INPUT="$subfile";

    printf "\n%s:" $subfile
    ./compilador "entradas/$( echo $INPUT| cut -d '/' -f 2)/$( echo $INPUT| cut -d '/' -f 3)" "saidas/$( echo $INPUT| cut -d '/' -f 2)/$( echo $INPUT| cut -d '/' -f 3)"
  done
done
