#include <iostream>

using namespace std;

template <typename Type>
class Vec
{
private:
    Type* arr;
    int size;
    int capacity;

public:
    Vec()
    {
		capacity = 10;
		size = 0;
		//arr = (int*) malloc(capacity * sizeof(int));
		arr = new Type[capacity];
    }

	Vec(int _size, int _capacity)
	{
		size = _size;
		capacity = _capacity;
	}

	void RemoveOnIndex(int indx)
	{
		for (int i = indx; i < size; ++i)
		{
			arr[i] = arr[i + 1];
		}

		--size;
	}

	void Insert(int indx, Type& element)
	{
		++size;
		if (!IsCapacityOk())
		{
			ChangeCapacity();
		}

    	for (int i = size - 1; i > indx; --i)
   	 	{
        	arr[i] = arr[i - 1];
    	}

    	arr[indx] = element;
	}

    void Print()
    {
		for (int i = 0; i < size - 1; ++i)
		{
	    	cout << arr[i] << endl;
		}
    }

    void Add(int value)
    {
		if (!IsCapacityOk())
		{
	    	ChangeCapacity();
		}
	
		arr[size] = value;
		size++;
    }  

    ~Vec()
    {
		delete[] arr;
    }  
public:
	Type& operator[] (const Type indx)
	{
		return arr[indx];
	}

private:
	bool IsCapacityOk()
	{
		bool flag = true;

		if (size == capacity)
			flag = false;

		return flag;
	}
	
	void ChangeCapacity()
	{
		capacity *= 10;
	    //int* temp = (int*) malloc(capacity * sizeof(int));
		Type* temp = new Type[capacity];
	    
	    for (int i = 0; i < size; ++i)
	    {
			temp[i] = arr[i];
	    }

	    delete[] arr;
	    arr = temp;
	}
};

int main()
{
    Vec <int> vec;

    for (int i = 0; i < 14; ++i)
    {
		vec.Add(i);
    }

	int elem = 99;
	vec.Insert(2, elem);

    vec.Print();
	cout << endl;
	vec.RemoveOnIndex(5);
	vec.Print();
	cout << endl;

	
	cout << vec[5] << endl;

	cout << endl;

	vec[7] = 1;
    vec.Print();

    return 0;
}