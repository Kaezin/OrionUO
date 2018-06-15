﻿/***********************************************************************************
**
** Weather.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/

#ifndef WEATHER_H
#define WEATHER_H

//Класс для работы с погодой
class CWeather
{
public:
    //Тип вогоды
    uchar Type = 0;
    //Максимальное количество эффектов на экране
    uchar Count = 0;
    //Текущее количество эффектов на экране
    uchar CurrentCount = 0;
    //Температура
    uchar Temperature = 0;
    //Время отрисовки
    uint Timer = 0;
    //Направление ветра
    char Wind = 0;
    //Таймер смены ветра
    uint WindTimer = 0;
    //Время последней смены анимации погоды
    uint LastTick = 0;
    //Скорость общей симуляции зависит от этого значения. Больше - медленней
    float SimulationRatio = 37.0f;

    CWeather();
    ~CWeather() { m_Effects.clear(); }

    //Погодные эффекты
    deque<CWeatherEffect> m_Effects;

    //Выключить погодные эффекты
    void Reset();

    //Сгенерировать эффекты
    void Generate();

    //Отрисовать погодные эффекты
    void Draw(int x, int y);
};

extern CWeather g_Weather;

#endif
