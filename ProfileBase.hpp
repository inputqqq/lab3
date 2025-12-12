// ProfileBase.hpp
#pragma once
#include <string>
#include <memory>
#include <iostream>

// Абстрактный базовый класс (feature: абстрактный класс)
// Демонстрирует: абстрактность (pure virtual), виртуальный деструктор
class ProfileBase {
public:
    ProfileBase() = default;
    virtual ~ProfileBase() = default; // виртуальный деструктор (требуется)

    // чисто виртуальная функция — вынуждает производные реализовать её
    virtual void showProfileInfo() const = 0;

    // метод-обёртка (не виртуальный) — вызывает виртуальную функцию внутри.
    // Это позволит продемонстрировать поведение виртуальной функции при вызове через не- виртуальную.
    void printViaNonVirtual() const {
        // Вызов виртуальной функции из невиртуального метода
        showProfileInfo();
    }

    // Клонирование (виртуальный метод для полиморфного копирования)
    virtual ProfileBase* cloneShallow() const = 0;
    virtual ProfileBase* cloneDeep() const = 0;
};
