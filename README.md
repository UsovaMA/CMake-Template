# CMake Template
Template for developing and testing C++ programs 

* Build system: cmake
* Tests: gtest
* Code style check: cpplint

## Build project with cmake

Call the command line from **sln** folder, execute the command

```cmake -G "Visual Studio 16 2019" ..```

to build the project for the specified Visual Studio version

## Main command for work with GitHub and git bash

### 0. Создание нового репозитория (пустой репозиторий с README в основной ветке)

```
git init
git add README.md
git commit -m "init commit"
git branch -M main
git remote add origin ссылка-до-ВАШЕГО-репозитория
git push -u origin main
```

### 1. Начало работы (клонирование репозитория, создание рабочей ветки)

```git clone ссылка-до-ВАШЕГО-репозитория```

Переключаем ветку из main/master на вашу рабочую ветку (если это ещё не сделано)

1. Если ветка уже у вас была создана, то просто переходим в неё

```git checkout имя-рабочей-ветки```

2. Если у вас нет другой рабочей ветки и только main/master, то создаёте рабочую ветку

```git branch имя-рабочей-ветки```

и переходите в неё

```git checkout имя-рабочей-ветки```

или одной командой создаём новую ветку и переходим в неё

```git checkout -b имя-рабочей-ветки```

### 2. Выкладывание результатов на GitHub

1. Добавить файлы, которые будут включены в текущий коммит

* это могут быть отдельные файлы, добавленные последовательным вызовом команд вида

```git add file_name.txt```

* можно проверить статус изменений вызовом команды

```git status```

и добавить ВСЕ изменённые файлы командой

```git add .```

* если вы удалили какие-то файлы, подхватить данные изменения коммитом можно с помощью добавления к данной команде ключа

```git add -u .```

2. Сформировать коммит при помощи специальной команды, добавив осмысленный комментарий (какие изменения проделаны)

```git commit –m "fix problem with magic numbers, add comments"```

Для формирования сразу пачки коммитов повторять действия 1, 2.

3. Для отправки результатов на GitHub использовать команду

```git push origin имя-рабочей-ветки```

или команду с ключом

```git push –u origin имя-рабочей-ветки```

**Замечание.** Если сделать git push ветки без ключа -u, git не свяжет локальную ветку с веткой удалённого репозитория. Смысл использовать ключ -u есть только при пуше новых веток, для существующих (связанных с удалёнными) веток каждый раз перезаписывать связку необязательно.

### Топ проблем с их решениями

**Ситуация 0.** Не могу залить на GitHub в КЛАССЕ (проблема в университетском компьютьерном классе), потому что git привязался к другому пользователю.

**Решение.** Зайти в Панель управления -> Учётные записи пользователей -> Диспетчер учётных данных -> Учётные данные Windows. Удалить учётные данные для github.

**Ситуация 1.** На этапе git clone я указал не свою ссылку (мой форк), а ссылку на оригинальный репозиторий. Теперь при git push git пишет, что у меня нет прав доступа к репозиторию пользователя ИМЯ.

**Решение.** Выполнить команду для привязки к СВОЕМУ репозиторию

```git remote set-url origin ссылка-до-ВАШЕГО-репозитория```

затем попробовать повторить (снова формировать коммит не нужно)

```git push origin название-рабочей-ветки```

**Ситуация 2.** Я пытаюсь сделать пуш, но git пишет, что на GitHub есть изменения в этой ветке, которые отсутствуют в вашей локальной копии на компьютере.
![image](https://user-images.githubusercontent.com/22386453/144020295-27641af1-22ea-434a-8d95-23b6da5f07db.png)

**Решение.** В первую очередь можно попробовать подкачать изменения с GitHub (актуализировать ветку), а потом свои залить изменения. Если коммиты при этом исчезнут, придётся создать их снова.

```
git pull origin название-рабочей-ветки
git push origin название-рабочей-ветки
```

 Можно попробовать залить изменения принудительно

```git push -f origin название-рабочей-ветки```

Чтобы таких ситуаций возникало меньше, прежде чем вносить новые изменения рекомендуется актуализировать ветку в соответсвии с GitHub

```git pull origin название-рабочей-ветки```

**Ситуация 3.** Забыл создать новую ветку и работал в master.

**Решение.** Если Вы закоммитили (git commit –m) уже кучу файлов (если нет - рекомендуется сделать, чтобы не потерять изменения), можно переместить все эти изменения в новую ветку можно с помощью следующих команд (действия выполняются в ветке master)

Если ветка еще не была создана

```git branch название-рабочей-ветки```

В противном случае переходить сразу к командам

```
git reset HEAD~ --hard
git checkout название-рабочей-ветки
```

**Ситуация 4.** Добавил к коммиту лишние файлы (например, папку Debug).

**Решение.** Если коммит ещё не был создан (сделано git add, но не было выполнено команды git commit) достаточно команды

```git reset имя-файла/папки-с-путём```

Если изменение было закоммичено, то и это поправимо. Придётся воспользоваться ещё несколькими командами

```
git reset --soft HEAD~1
git reset имя-файла/папки-с-путём
rm имя-файла/папки-с-путём
git commit
```

Команда rm удалит данный файл/папку!

Про менее частые проблемы можно прочитать здесь: https://htmlacademy.ru/blog/boost/frontend/first-aid-git

## Пример

Пусть у программиста был проект с файлами, всё это он хранил в ветке development:

* README.md - описание проекта, 
* main.cpp - основной файл с запускаемым приложением, 
* functions.h - заголовочный файл статической библиотеки, 
* functions.cpp - реализация статической библиотеки. 

Не думая о коммитах, о проделал следующее: добавил новую функцию в библиотеку, встроил её использование в приложение, изменил структуру приложения (добавил меню пользователя), изменил описание проекта.

Он понял, что заливать всё это одним коммитом очень нагрузочно и решил отделить коммиты

```
git add lib/functions.h
git add lib/functions.cpp
git commit –m "add new method in library"
git add main.cpp
git commit –m "add communication with user in application"
git add README.md
git commit –m "fix project discription"
git push origin development
```

Затем он залил данные коммиты на гитхаб и понял, что по ряду причин не хочет выносить реализацию в файл functions.cpp. Он перенёс его содержимое в functions.h и удалил. Более изменений не было, поэтому он выполнил команду добавления для всех изменённых файлов, добавив специальный ключ, чтобы подхватить в коммит удаление файла

```
git add -u .
git commit –m "fix library structure"
git push origin development
```
