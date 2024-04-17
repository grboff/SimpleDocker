## Part 1. Готовый докер

<img src="pic/1.png" alt="part1" width="700"/>

- 1.1 Взяла официальный докер образ с **nginx** и выкачала его при помощи `docker pull`

<img src="pic/2.png" alt="part1" width="700"/>

- 1.2 Проверила наличие докер образа через `docker images`

<img src="pic/3.png" alt="part1" width="700"/>

- 1.3 Запустила докер образ через `docker run -d [image_id|repository]`

<img src="pic/4.png" alt="part1" width="700"/>

- 1.4 Проверила, что образ запустился через `docker ps`

<img src="pic/5.png" alt="part1" width="700"/>

- 1.5 Посмотрела информацию о контейнере через `docker inspect [container_id|container_name]`

<img src="pic/6.1.png" alt="part1" width="700"/>

- 1.6.1 Размер контейнера

<img src="pic/6.2.png" alt="part1" width="700"/>

- 1.6.2 Список замапленных портов

>Замапленные порты (Mapped ports) - это механизм, который позволяет связать порты на хостовой машине
>с портами внутри контейнера Docker. Это позволяет сделать приложения в контейнере доступными
>для других приложений на хостовой машине или в сети.

<img src="pic/6.3.png" alt="part1" width="700"/>

- 1.6.3 ip контейнера

<img src="pic/7.png" alt="part1" width="700"/>

- 1.7 Остановила докер образ через `docker stop [container_id|container_name]`

<img src="pic/8.png" alt="part1" width="700"/>

- 1.8 Проверила, что образ остановился через `docker ps`

<img src="pic/9.png" alt="part1" width="700"/>

- 1.9 Запустила докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду *run*

<img src="pic/10.png" alt="part1" width="700"/>

- 1.10 Проверила, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**

<img src="pic/11.png" alt="part1" width="700"/>

- 1.11 Перезапустила докер контейнер через `docker restart [container_id|container_name]`

<img src="pic/12.png" alt="part1" width="700"/>

- 1.12 Проверила любым способом, что контейнер запустился

## Part 2. Операции с контейнером

<img src="pic/13.png" alt="part2" width="700"/>

- Прочитала конфигурационный файл *nginx.conf* внутри докер контейнера через команду *exec*

<img src="pic/14.png" alt="part2" width="700"/>

- Создать на локальной машине файл *nginx.conf*

<img src="pic/15.png" alt="part2" width="700"/>

- Настроить в нем по пути */status* отдачу страницы статуса сервера **nginx**

<img src="pic/16.png" alt="part2" width="700"/>

- Скопировать созданный файл *nginx.conf* внутрь докер образа через команду `docker cp`


<img src="pic/17.png" alt="part2" width="700"/>

- Перезапустить **nginx** внутри докер образа через команду *exec*


<img src="pic/18.png" alt="part2" width="700"/>

- Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**


<img src="pic/19.png" alt="part2" width="700"/>

- Экспортировать контейнер в файл *container.tar* через команду *export*


<img src="pic/20.png" alt="part2" width="700"/>

- Остановить контейнер


<img src="pic/21.png" alt="part2" width="700"/>

- Удалить образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры


<img src="pic/22.png" alt="part2" width="700"/>

- Удалить остановленный контейнер


<img src="pic/23.png" alt="part2" width="700"/>

- Импортировать контейнер обратно через команду *import*


<img src="pic/24.png" alt="part2" width="700"/>

- Запустить импортированный контейнер


<img src="pic/25.png" alt="part2" width="700"/>

- Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**


## Необязательная документация. 
## Part 3. Мини веб-сервер

<img src="pic/26.png" alt="part2" width="700"/>

- запускаю контейнер с образом nginx 

<img src="pic/27.png" alt="part2" width="700"/>

- копирую написанные файлы в контейнер 

- захожу в контейнер в интерактивном режиме через команду docker exec -it [container id] /bin/bash

<img src="pic/28.png" alt="part2" width="700"/>

- устанавливаю ПО для запуска сервера 

<img src="pic/29.png" alt="part2" width="700"/>

- запускаю сервер, перезагружаю nginx 

<img src="pic/30.png" alt="part2" width="700"/>

- Вижу что на нужном мне порту localhost отдается моя страничка 

## Part 4. Свой докер

<img src="pic/31.png" alt="part2" width="700"/>

- Собираю докер образ, при этом указывая имя и тег 

<img src="pic/32.png" alt="part2" width="700"/>

- Видим, что все корректно собралось 

<img src="pic/33.png" alt="part2" width="700"/>

-  Запускаю собранный докер образ с маппингом 81 порта на 80 на локальной машине и маппингом папки *./nginx* внутрь контейнера по адресу, где лежат конфигурационные файлы **nginx**'а

<img src="pic/34.png" alt="part2" width="700"/>

- Проверить, что по localhost:80 доступна страничка написанного мини сервера

<img src="pic/35.png" alt="part2" width="700"/>

- Проверить, что теперь по *localhost:80/status* отдается страничка со статусом **nginx**

## Part 5. **Dockle**

<img src="pic/36.png" alt="part2" width="700"/>

- при запуске dockle получаю следующие ошибки: 
   - CIS-DI-0010: Не храните учетные данные в переменных окружения или файлах
   - DKL-DI-0005: нужно очистить кеш после выполнения команды apt-get 
   - CIS-DI-0001: создать пользователя для контейнера

<img src="pic/37.png" alt="part2" width="700"/>

- исправленный dockerfile в соответствии с рекомендациями. Отсутствуют warn и fatal
> https://github.com/goodwithtech/dockle/issues/130


## Part 6. Базовый **Docker Compose**

> исходные файлы в каталоге 

<img src="pic/38.png" alt="part2" width="700"/>
<img src="pic/39.png" alt="part2" width="700"/>

- собираем и запускаем проект 

<img src="pic/40.png" alt="part2" width="700"/>

-  в браузере по *localhost:80* отдается написанная страничка, как и ранее
