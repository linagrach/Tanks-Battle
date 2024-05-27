# **Игра «Tanks Battle»‎‎**
_____
## 1. Описание проекта
Проект "Tanks Battle" представляет собой аналог игры "Battle City" для соревнования между двумя игроками, разработанную с использованием среды программирования Microsoft Visual Studio на языке C++, с применением графической библиотеки SFML (Simple and Fast Multimedia Library). Цель игры - попасть выстрелом в танк противника, набирая этим очки, и набрать очков больше, чем оппонент, до достижения заданного числа очков.

![icon](https://github.com/linagrach/Tanks-Battle/blob/master/image%20130.png, "Tanks Battle!")

_____
## 2. Демонстрация
### Изображения состояний игры:
+ Меню

![menu](https://github.com/linagrach/Tanks-Battle/blob/master/image%20130.png, "Menu")

+ Игра

![game1](https://github.com/linagrach/Tanks-Battle/blob/master/image%2062.png, "Gameplay")
![game2](https://github.com/linagrach/Tanks-Battle/blob/master/image%2067.png, "Gameplay")

+ Победа первого игрока

![green wins](https://github.com/linagrach/Tanks-Battle/blob/ce08b6dc721953f0a07cb8f7fc7dfe7ba94d6c1c/image%2065.png, "Green Wins!")

+ Победа второго игрока

![yellow_wins](https://raw.githubusercontent.com/linagrach/Tanks-Battle/master/image%2064.jpg, "Yellow wins!")

_____
## 3. Технологии/фишки/уникальные составляющие, использованные в проекте

В проекте использованы различные технологии и уникальные решения, которые делают его интересным и увлекательным:
+ Использование библиотеки SFML: Проект активно использует Simplified Fast Multimedia Library (SFML) для рендеринга графики. Это обеспечивает гладкую и качественную отрисовку игровых объектов и интерфейса.
+ Управление Игроками: Передвижение первого игрока управляется клавишамами-стрелками ``` ← ↑ ↓ → ```, для выстрелов первый игрок использует ``` L ```, в то время как второй игрок использует клавиши ``` WASD ```, выстрел второго игрока - клавиша``` V ```. Это позволяет обоим игрокам одновременно и комфортно управлять своими контроллерами на одной клавиатуре.
+ PvP Режим: Игра разработана для тактического соревнования между двумя игроками, делая упор на социальный аспект и взаимодействие между людьми в реальной жизни.
+ Система Очков: Победа наступает, когда один из игроков набирает 3 балла. Это добавляет стратегичность и планирование в игру, заставляя игроков мыслить аналитически.
+ Состояния Игры: Проект включает в себя несколько состояний игры, таких как меню, сама игра, и финальная заставка с объявлением победителя. Это структурирует игровой процесс и делает его более разнообразным и динамичным.
+ Графический Интерфейс: Простой и интуитивно понятный интерфейс способствует быстрому освоению игры пользователем.
+ Коллизии выстрелов и танков: Движения танков и выстрелов реализованы с учетом пространства и карты и обработки столкновений и движения. Это улучшает пользовательский опыт в игре. SFML упрощает задачу, предоставляя инструменты для работы с движением и позволяя глубже сфокусироваться на логике игры.
______
## 4. Проблемы, с которыми пришлось столкнуться

В проекте по созданию игры "Аэрохоккей" на C++ с использованием библиотеки SFML возникли следующие проблемы:
+ Обработка столкновений: реализация движения и поведения танков и выстрелов с учетом карты
+ Реализация состояний игры: сложности с созданием главного меню, экранов победы/проигрыша и их интеграцией в общий игровой процесс.
+ Различные свойства блоков карты: возникающие трудности с разделением свойств каждого блока карты и корректное их поведение при столкновении с выстрелами. 

____
## 5. Техническое описание проекта

### Как установить:
+ Предварительные требования: Убедитесь, что на вашем компьютере установлены Visual Studio и компилятор для C++, а также установлена и настроена библиотека SFML.
+ Скачивание проекта: Скачайте исходный код проекта из репозитория или любого источника, указанного разработчиком.
+ Открытие проекта: Откройте файл проекта ```(.sln)``` в Visual Studio.
+ Конфигурация SFML: Убедитесь, что в настройках проекта указаны пути к библиотекам и заголовочным файлам SFML. Включите копирование файлов ````DLL SFML```` в папку с исполняемым файлом проекта.
+ Компиляция: Соберите решение, нажав ```"Build Solution"``` или используя клавишу ```F7```.
+ Запуск: Запустите проект через Visual Studio или открыв исполняемый файл в папке с проектом.

### Управление в игре:
+ Первый игрок управляется клавишами-стрелками ``` ← ↑ ↓ → ```(вверх, вниз, вправо, влево), а управление выстрелами - клавиша ``` L ```.
+ Второй игрок управляется клавишами  ``` WASD ```, а управление выстрелами - клавиша ``` V ```.

### Игровая механика:
- Игра рассчитана на 2 игроков (PvP).
- Цель игры - первым набрать 3 балла, попадая выстрелом в танк противника
- Игровое поле представляет собой набор расположенных по полею блоков Кирпича, Камня и Земли, которые по разному взаимодействуют с выстрелами и танками  
- Управление игроками осуществляется для перемещения только в четыре стороны: вправо, влево, вверх и вниз, такая же механика и у выстрела: в какую сторону направлен танк, в такую сторону и произойдет выстрел
- Избежать попадания выстрела можно с помощью ландшафта карты, укрываясь за блоком Кирпича или Камня

### Игровые состояния:
- Меню: для начала игры нажмите ```Enter```.
- Игра: игровой процесс, где игроки соревнуются.
- Финальная заставка: отображает победителя; для перезапуска игры нажмите ```Space```, для выхода из игры - ```Escape```.

### Заметки:
- Возможны кастомизации игры путем изменения графики, звуков и игровой механики через изменения в коде.
- Следите за обновлениями библиотеки SFML и совместимости с используемой версией Visual Studio.
