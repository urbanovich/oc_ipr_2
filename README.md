1. Отсортировать в заданном каталоге (аргумент 1 командной строки) 
и во всех его подкаталогах файлы по следующим критериям 
(аргумент 2 командной строки, задаётся в виде целого числа):
    1 – по размеру файла, 
    2 – по имени файла. 
Записать отсортированные файлы в новый каталог (аргумент 3 командной строки). 
Процедуры копирования  должны запускаться в отдельном процессе для каждого 
копируемого файла с использованием функций read() и write(). 
Каждый процесс выводит на экран свой pid, полный путь, имя копируемого файла и число скопированных байт. 
Число запущенных процессов в любой момент времени не должно превышать N (вводится пользователем). 
Проверить работу программы для каталога /usr/include N=6.. 

после компиляции выполнить:

cd /path/to/project;
sudo chmod 777 -R .;
./oc_ipr_2 /usr/include 1 /path/to/desc_dir 6;