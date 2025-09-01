// #ifndef ARRAY_LIST_TPP
// #define ARRAY_LIST_TPP

// #include <string>
// #include <iostream>
using namespace std;

template <typename T>
ArrayList<T>::ArrayList(int i) {
    buffer = new T[i];
    maxSize = i;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    clear();
}

template <typename T>
void ArrayList<T>::append(const T& elem) {
    if (index >= maxSize) {
        throw string("too many elements in append()");
    }
    buffer[index] = elem;
    index ++;
}

template <typename T>
void ArrayList<T>::clear() {
    index = 0;
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    clear();
    delete buffer;
    buffer = new T[copyObj.getMaxSize()];
    for (int i = 0; i < copyObj.getLength(); i++) {
        buffer[i] = copyObj.getElement(i);
    }
}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    if (position < index && position >= 0) {
        return buffer[position];
    } else {
        throw string("Index out of bounds in getElement()");
    }
}

template <typename T>
int ArrayList<T>::getLength() const {
    return index;
}

template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    cout << "hey" << endl;
    if (index >= maxSize) {
        // throw 3;
        // throw string("Too many elements with insert()");
        
    } else if (position >= 0 && position <= index) {
        for (int i = index; i >= position; i--) {
            buffer[i+1] = buffer[i];
        }
        buffer[position] = elem;
        index ++;
    } else {
        // throw 3;
        // throw string("Index out of bounds with insert()");
    }
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayList<T>::remove(int position) {
    if (position >= index || position < 0) {
        throw string("Index out of bounds in remove()");
    } else {
        for (int i = position; i < index; i++) {
            buffer[i] = buffer[i+1];
        }
        index--;
    }
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    if (position >= 0 && position < index) {
        buffer[position] = elem;
    } else {
        throw string("Index out of bounds in replace()");
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        for (int i = 0; i < myObj.length; i++) {
            outStream << myObj.buffer[i] << ' ';
        }
        outStream << endl;
    }

    return outStream;
}

// template <typename T>
// ArrayList<T>::TooManyException::TooManyException(string s) {
//     e = s;
// }

// template <typename T>
// string ArrayList<T>::TooManyException::what() const {
//     return e;
// }

// template <typename T>
// ArrayList<T>::IndexOutOfBoundsException::IndexOutOfBoundsException(string s) {
//     e = s;
// }

// template <typename T>
// string ArrayList<T>::IndexOutOfBoundsException::what() const {
//     return e;
// }
