#include <iostream>
using namespace std;

class ResourceHolder {
private:
    int* data;
    int size;

    ResourceHolder(int initial_size) : size(initial_size) {
        data = new int[size];
        cout << "Выделено " << size * 4 << " байтов памяти." << endl;
    }
    ~ResourceHolder() {
        delete[] data;
        data = nullptr;
        cout << "Память освобождена" << endl;
    }
    
    //Конструктор копирования: Глубокое копирование
    ResourceHolder(const ResourceHolder& other) : size(other.size) {
        data = new int[other.size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    ResourceHolder(ResourceHolder& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
    }
    ResourceHolder operator=(ResourceHolder& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        ResourceHolder
    }
};



class vehicle {
protected:
    float скорость;
    int количество_колёс;
    int макс_пассажиров;

public:
    virtual void завести() const = 0;
    float получить_скорость() const {
        return скорость;
    }
    int получить_количество_колёс() const {
        return количество_колёс;
    }
    int получить_макс_пассажиров() const {
        return макс_пассажиров;
    }
};

class car : public vehicle {
public:
    car() : car(0, 0) {
    }
    car(float _скорость, int _макс_пассажиров) {
        скорость = _скорость;
        количество_колёс = 4;
        макс_пассажиров = _макс_пассажиров;
    }

    void завести() const override {
        std::cout << "*врунь-врунь*";
    }

    void характеристики() const {
        std::cout << "Скорость: " << скорость << "\n"
            << "Максимальное количество пассажиров: " << макс_пассажиров << std::endl
            << "Количество колёс: " << количество_колёс << std::endl;
    }
    car operator+(const car &other_car) const {
        return car(скорость + other_car.скорость, макс_пассажиров + other_car.макс_пассажиров);
    }
    ~car() {

    }

};

int main()
{
    setlocale(LC_ALL, "ru");
    car машина(60.0, 4);
    car машина2(60.0, 4);
    car машина3 = машина + машина2;
    машина.характеристики();
    машина2.характеристики();
    машина3.характеристики();

    машина.завести();
}