//
// Created by Islombek on 26.09.2021.
//

//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for(int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
// я решил игнорировать невалидные обьекты
void In(container &c, std::ifstream &ifst) {
    while(!ifst.eof()) {
        if((c.cont[c.len] = In(ifst)) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
// InRnd по идее никогда не возвращает nullptr, но это лишний нвариант, который может потом нарушиться
// так что я не стал его вводаить, в место этого, игнорирую невалидный обьект, если InRnd вернет его
void InRnd(container &c, int size) {
    while(c.len < size) {
        if((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << std::endl;
    for(int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
}


//------------------------------------------------------------------------------
// Сортирвка прямым выбором минимума. Сортирует контейнер по неубыванию
void StraightSelectionSort(container &c) {
    for (int i = 0; i < c.len; ++i) {
        int min_index = i; // первые i мы уже отсочтирвали
        //первое не отсортированное число находится под индексом i

        for (int j = i; j < c.len; ++j) {
            if (OptimalTime(*(c.cont[j])) < OptimalTime(*(c.cont[min_index]))) {
                min_index = j;
            }
        }
        // мы нашли индекс минимального не отсортированного элемента
        std::swap(c.cont[i], c.cont[min_index]);
        // устанавливаем минимум, на первую не отсортированную позицию тем самым делаем её сортирванной
        // я считаю, что std::swap вполне себе не противоречит идеям C, не уверен, есть ли она там,
        // но не вижу ничего плохого в использовании, даже если её нет в С.
    }
}