# Тесты для лабораторной работы №5

## Входные данные
Аргументы командной строки, файл со структурами, записанными в бинарном виде

## Выходные данные
Файл со структурами, записанными в бинарном виде

## Позитивные тесты:
Сортировка:
- 01 - Все цены одинаковые, количества одинаковые;
- 02 - Только одна структура;
- 03 - Все цены разные - упорядочены, количества - упорядочены;
- 04 - Все цены разные - упорядочены, количества - в случайном;
- 05 - Все цены разные - упорядочены в обратном порядке;
- 06 - Все цены разные - в случайном порядке;

- 07 - Все подстрока - название товара, товар такой один;
- 08 - Несколько товаров, оканчивающихся на подстроку;

## Негативые тесты:
- 01 - Отсутствие файла;
- 02 - Размер файла не кратен размеру структуры;
- 03 - Не правильное количество аргументов;
- 04 - Неизвестые аргументы;
- 05 - Нет товаров, оканчивающихся на подстроку