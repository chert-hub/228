#include <iostream>
#include <vector>
#include <functional>

template<typename T>
class IntArray
{
private:
    int m_length{};
    int *m_data{};
	
public:
    IntArray() = default;
 
    IntArray(int length):
        m_length{ length }
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length]{};
    }
 
    ~IntArray()
    {
        delete[] m_data;
        // здесь нам не нужно устанавливать m_data в значение null
        // или m_length в 0, так как объект в любом случае будет
        // уничтожен сразу после этой функции
    }
 
    void empty()
    {
        delete[] m_data;
        // Нам нужно убедиться, что мы установили здесь m_data
        // равным nullptr, иначе это оставит указатель 
        // указывающим на освобожденную память!
        m_data = nullptr;
        m_length = 0;
    }
	
 
    // reallocate изменяет размер массива. Любые существующие элементы
    // будут уничтожены. Эта функция работает быстро.
    void reallocate(int newLength)
    {
        // Сначала мы удаляем все существующие элементы
        erase();
 
        // Если теперь наш массив будет пустым, возвращаемся отсюда
        if (newLength <= 0)
            return;
 
        // Затем нам нужно разместить новые элементы
        m_data = new int[newLength];
        m_length = newLength;
    }
 
    // resize изменяет размер массива. Любые существующие элементы
    // будут сохранены. Эта функция работает медленно.
    void resize(int newLength)
    {
        // если массив уже имеет нужную длину, мы закончили
        if (newLength == m_length)
            return;
 
        // Если мы изменяем размер до пустого массива, делаем это и возвращаемся
        if (newLength <= 0)
        {
            erase();
            return;
        }
 
        // Теперь мы можем предположить, что newLength - это как минимум 1 элемент.
        // Этот алгоритм работает следующим образом:
        // Сначала размешаем новый массив.
        // Затем копируем элементы из существующего массива в новый массив.
        // Как только это будет сделано, можно уничтожить старый массив
        // и заставить m_data указывать на новый массив.
 
        // Сначала мы должны разместить новый массив
        int *data{ new int[newLength] };
 
        // Затем нам нужно выяснить, сколько элементов скопировать из
        // существующего массива в новый массив. Мы хотим скопировать
        // столько элементов, сколько есть в меньшем из двух массивов.
        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
 
            // Теперь копируем элементы один за другим
            for (int index{ 0 }; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }
 
        // Теперь мы можем удалить старый массив, потому что он нам больше не нужен
        delete[] m_data;
 
        // И вместо него используем новый массив! Обратите внимание, что это просто
        // заставляет m_data указывать на адрес нового массива, который мы
        // разместили динамически. Поскольку данные были размещены динамически,
        // они не будут уничтожены, когда выйдут за пределы области видимости.
        m_data = data;
        m_length = newLength;
    }
 
    void insertBefore(int value, int index)
    {
        // Проверяем значение нашего индекса на корректность
        assert(index >= 0 && index <= m_length);
 
        // Сначала создаем новый массив на один элемент больше старого массива
        int *data{ new int[m_length+1] };
 
        // Копируем все элементы до индекса
        for (int before{ 0 }; before < index; ++before)
            data [before] = m_data[before];
 
        // Вставляем наш новый элемент в новый массив
        data[index] = value;
 
        // Копируем все значения после вставленного элемента
        for (int after{ index }; after < m_length; ++after)
            data[after+1] = m_data[after];
 
        // Наконец, удаляем старый массив и используем вместо него новый
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
 
    void remove(int index)
    {
        // Проверяем значение нашего индекса на корректность
        assert(index >= 0 && index < m_length);
 
        // Если это последний элемент в массиве,
        // делаем массив пустым и выходим
        if (m_length == 1)
        {
            erase();
            return;
        }
 
        // Сначала создаем новый массив на один элемент меньше старого массива
        int *data{ new int[m_length-1] };
 
        // Копируем все элементы до индекса
        for (int before{ 0 }; before  < index; ++before)
            data[before] = m_data[before];
 
        // Копируем все значения после удаленного элемента
        for (int after{ index+1 }; after < m_length; ++after)
            data[after-1] = m_data[after];
 
        // Наконец, удаляем старый массив и используем вместо него новый
        delete[] m_data;
        m_data = data;
        --m_length;
    }
 
    // Пара дополнительных функций для удобства
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }
 
    int getLength() const { return m_length; }
};
 
int main()
{

	return 0;
}







