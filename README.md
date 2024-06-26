# О программе
Утилита для копирования перемещения файлов на ANSI-C. 

# Использование

Копирование файла
```powershell
./fmv C:\file.txet + C:\new_catalog\copy.text
```
Перемещение файла
```batch
./fmv C:\file.text - C:\new_catalog\file.text
```
Изменение имени и расширения
```batch
./fmv C:\file.text - C:\new_name.text
```
# TODO:
У меня не хватает мозга, но при переносе содержимого файла, структура теряется.
 - Изменить ```fcopy()```
```C
int fcopy(char* from, char* toward);
```
