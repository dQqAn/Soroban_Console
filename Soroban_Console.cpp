#include <iostream>
#include <string>
#include<conio.h>
using namespace std;

struct SinglyNode
{
	string elem;										// element name
	int score;											// element score
	SinglyNode* next;									// next item in the list
};

struct SinglyLinkedList
{
	SinglyNode* head;									// pointer to the head of list

	SinglyLinkedList();									// empty list constructor
	~SinglyLinkedList();								// destructor

	bool empty() const;									// is list empty?
	const string& front() const;						// get front element
	void addFront(const string& e, const int& i);		// add to front of list
	void addBack(const string& e, const int& i);		// add to back of list
	void removeFront();									// remove front item of list
	void removeBack();									// remove back item of list
	void print();

	void insertOrdered(const string& e, const int& i);
	void insertOrdered(SinglyNode* newNode, SinglyNode* previous);

	void removeOrdered(const string& e, const int& i);

	SinglyLinkedList* mergeLists(SinglyLinkedList* list2);
};

SinglyLinkedList::SinglyLinkedList()							// constructor
{
	head = NULL;
}

SinglyLinkedList::~SinglyLinkedList()							// destructor
{
	while (!empty()) removeFront();
}

bool SinglyLinkedList::empty() const							// is list empty?
{
	return head == NULL;
}

const string& SinglyLinkedList::front() const					// get front element
{
	return head->elem;
}

void SinglyLinkedList::addFront(const string& e, const int& i)	// add to front of list
{
	SinglyNode* v = new SinglyNode;							// create new node
	v->elem = e;										// store data
	v->score = i;
	v->next = head;										// head now follows v
	head = v;										// v is now the head
}

void SinglyLinkedList::removeFront()							// remove front item
{
	if (empty())
	{
		cout << "List is empty !" << endl;
		return;
	}

	SinglyNode* temp = head;									// save current head
	head = head->next;							// skip over old head
	delete temp;												// delete the old head
}


void SinglyLinkedList::addBack(const string& e, const int& i)
{
	SinglyNode* v = new SinglyNode;
	v->elem = e;
	v->score = i;
	v->next = NULL;

	if (head == NULL) head = v;
	else
	{
		SinglyNode* first = head;
		while (first->next != NULL) first = first->next;
		first->next = v;
	}
}

void SinglyLinkedList::removeBack()
{
	if (empty())
	{
		cout << "List is empty !" << endl;
		return;
	}

	SinglyNode* previous = head;

	// kalan tek düğümü sil
	if (previous->next == NULL)
	{
		head = NULL;
		delete previous;
	}
	// en az iki düğüm var
	else
	{
		while (previous->next->next != NULL)
			previous = previous->next;

		delete previous->next;											// previous->next 'i silinir
		previous->next = NULL;
	}
}

void SinglyLinkedList::print()
{
	if (empty())
	{
		cout << "List is empty !" << endl;
		return;
	}

	SinglyNode* first = head;
	while (first != NULL)
	{
		cout << first->elem << "\t" << first->score << endl;
		first = first->next;
	}
}

//-----------------------------------------------------------------------------

class inputNumber {
public:
	inputNumber(int);
	inputNumber();
	
	SinglyLinkedList out1, out2, out3, out4, out5;

	SinglyLinkedList list;

	int getValue(int);

	void write();

	int getStep();

	void writeFunc(int, SinglyLinkedList*, inputNumber*);

	void sumFunction(inputNumber*, inputNumber*); 
	void subtractionFunction(inputNumber * , inputNumber *);

	void multiplicationFunction(inputNumber*, inputNumber*);


	void divisionFunction(inputNumber*, inputNumber*);

	void printFunc(inputNumber*);

	void setList(inputNumber*);

	int valueF1, valueF2 , valueF3 , valueF4 , valueF5 ;
	int valueS1 , valueS2 , valueS3 , valueS4 , valueS5 ;

private:

	int stepTemp;
	int no;

};

void inputNumber::printFunc(inputNumber* list) {

	cout << "5" << "\t" << list->out1.head->score << "\t" << list->out2.head->score << "\t" << list->out3.head->score << "\t" << list->out4.head->score << "\t" << list->out5.head->score << endl;
	cout << "1" << "\t" << list->out1.head->next->score << "\t" << list->out2.head->next->score << "\t" << list->out3.head->next->score << "\t" << list->out4.head->next->score << "\t" << list->out5.head->next->score << endl;
	cout << "1" << "\t" << list->out1.head->next->next->score << "\t" << list->out2.head->next->next->score << "\t" << list->out3.head->next->next->score << "\t" << list->out4.head->next->next->score << "\t" << list->out5.head->next->next->score << endl;
	cout << "1" << "\t" << list->out1.head->next->next->next->score << "\t" << list->out2.head->next->next->next->score << "\t" << list->out3.head->next->next->next->score << "\t" << list->out4.head->next->next->next->score << "\t" << list->out5.head->next->next->next->score << endl;
	cout << "1" << "\t" << list->out1.head->next->next->next->next->score << "\t" << list->out2.head->next->next->next->next->score << "\t" << list->out3.head->next->next->next->next->score << "\t" << list->out4.head->next->next->next->next->score << "\t" << list->out5.head->next->next->next->next->score << endl << endl;


}

void inputNumber::divisionFunction(inputNumber* first, inputNumber* second) {

	int fNo = first->no;
	int sNo = second->no;
	
	inputNumber mList;

	mList.setList(&mList);

	SinglyLinkedList* arrayOut[5] = { &mList.out5, &mList.out4, &mList.out3, &mList.out2, &mList.out1 };

	int section = 0;

	if (fNo >= sNo)
	{

		while (fNo >= sNo)
		{
			sNo += second->no;
			section++;
		}

		sNo = sNo - second->no;

		/*int remainder = fNo - sNo;
		cout << "R1: " << remainder << endl;
		remainder = 0;*/

		//section
		
		string tempSection = to_string(section);

		int ctr = 0;
		while (ctr < tempSection.length())
		{
			int tempInt = stoi(tempSection.substr(tempSection.size() - ctr - 1, 1));

			cout << "Division: " << endl;
			mList.writeFunc(tempInt, arrayOut[ctr], &mList);
			ctr++;
		}
		ctr = 0; 

		_getch();
		system("cls");
		printFunc(&mList);
		_getch();
	}
	else {

		while (fNo <= sNo)
		{
			fNo += first->no;
			section++;
		}

		fNo = fNo - first->no;

		/*int remainder = sNo - fNo;
		cout <<"R2: " << remainder << endl;
		remainder = 0;*/

		//section

		string tempSection = to_string(section);

		int ctr = 0;
		while (ctr < tempSection.length())
		{
			int tempInt = stoi(tempSection.substr(tempSection.size() - ctr - 1, 1));

			cout << "Division: " << endl;
			mList.writeFunc(tempInt, arrayOut[ctr], &mList);
			ctr++;
		}
		ctr = 0;

		_getch();
		system("cls");
		printFunc(&mList);
		_getch();
	}

	section = 0;


	cout << "Different method for division: " << first->no / second->no << endl;
	printFunc(&mList);

}

void inputNumber::multiplicationFunction(inputNumber* first, inputNumber* second) {

	int fNo = first->no;
	int sNo = second->no;

	if (fNo >= sNo)
	{
		valueF1 = first->getValue(1);
		valueF2 = first->getValue(2);
		valueF3 = first->getValue(3); //1 birler, 2 onlar, 3 yüzler
		valueF4 = first->getValue(4);
		valueF5 = first->getValue(5);

		valueS1 = second->getValue(1);
		valueS2 = second->getValue(2);
		valueS3 = second->getValue(3);
		valueS4 = second->getValue(4);
		valueS5 = second->getValue(5);
	}
	else {
		valueF1 = second->getValue(1);
		valueF2 = second->getValue(2);
		valueF3 = second->getValue(3); //1 birler, 2 onlar, 3 yüzler
		valueF4 = second->getValue(4);
		valueF5 = second->getValue(5);

		valueS1 = first->getValue(1);
		valueS2 = first->getValue(2);
		valueS3 = first->getValue(3);
		valueS4 = first->getValue(4);
		valueS5 = first->getValue(5);
	}

	inputNumber mList;

	mList.setList(&mList);

	
	int tp = 0;

	int arrayF[5] = { valueF1 ,valueF2 ,valueF3 ,valueF4 ,valueF5 };
	int arrayS[5] = { valueS1 ,valueS2 ,valueS3 ,valueS4 ,valueS5 };

	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;
	int column[9] = { c1, c2, c3, c4, c5 ,c6 ,c7 ,c8 ,c9 };

	int arrayCounterF = 0;
	int arrayCounterS = 0;

	SinglyLinkedList* arrayOut[5] = { &mList.out5, &mList.out4, &mList.out3, &mList.out2, &mList.out1 };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			int tmp = 0;

			int w1 = ((arrayF[i] > arrayS[j]) ? arrayF[i] : arrayS[j]);

			int w2 = ((arrayF[i] < arrayS[j]) ? arrayF[i] : arrayS[j]);


			while ((tmp < w1) && (w1 > w2))
			{

				tp += w2;
				tmp++;
			}

			while ((tmp < w2) && (w2 > w1))
			{

				tp += w1;
				tmp++;
			}


			while ((tmp != w1) && (w1 == w2))
			{
				tp += w1;

				tmp++;
			}

			int cVal = 0;
			
			if (i == 0)
			{
				cVal = (column[j] + (tp)) / 10;
				column[j] = (column[j] + (tp)) % 10;
				
				column[j + 1] = column[j + 1] + cVal;

			}
			else {
				cVal = (column[j + i] + (tp)) / 10;
				column[j + i] = ((column[j + i] + (tp)) % 10);
				
				column[i + j + 1] = column[i + j + 1] + cVal;
			}
			cVal = 0;
			tp = 0;
			tmp = 0;

			cout << "Multiplication: " << endl;
			mList.writeFunc((column[i]), arrayOut[i], &mList);

		}
		
	}

	
	cout << "Different method for multiplication: " << first->no * second->no << endl;
	printFunc(&mList);

}

void inputNumber::setList(inputNumber* setList) {

	int sumCounter = 1;

	setList->out1.addFront(to_string(5), 0);
	setList->out2.addFront(to_string(5), 0);
	setList->out3.addFront(to_string(5), 0);
	setList->out4.addFront(to_string(5), 0);
	setList->out5.addFront(to_string(5), 0);

	while (sumCounter <= 4)
	{
		setList->out1.addBack(to_string(1), 0);
		setList->out2.addBack(to_string(1), 0);
		setList->out3.addBack(to_string(1), 0);
		setList->out4.addBack(to_string(1), 0);
		setList->out5.addBack(to_string(1), 0);

		sumCounter++;
	}

}

inputNumber::inputNumber() {

}

void inputNumber::subtractionFunction(inputNumber* first, inputNumber* second) {

	int fNo = first->no;
	int sNo = second->no;

	if (fNo >= sNo)
	{
		valueF1 = first->getValue(1);
		valueF2 = first->getValue(2);
		valueF3 = first->getValue(3); //1 birler, 2 onlar, 3 yüzler
		valueF4 = first->getValue(4);
		valueF5 = first->getValue(5);

		valueS1 = second->getValue(1);
		valueS2 = second->getValue(2);
		valueS3 = second->getValue(3);
		valueS4 = second->getValue(4);
		valueS5 = second->getValue(5);
	}
	else {
		valueF1 = second->getValue(1);
		valueF2 = second->getValue(2);
		valueF3 = second->getValue(3); //1 birler, 2 onlar, 3 yüzler
		valueF4 = second->getValue(4);
		valueF5 = second->getValue(5);

		valueS1 = first->getValue(1);
		valueS2 = first->getValue(2);
		valueS3 = first->getValue(3);
		valueS4 = first->getValue(4);
		valueS5 = first->getValue(5);
	}

	inputNumber sumList;

	sumList.setList(&sumList);

	//Different method for subtraction.
	int bit = 0;
	if ((valueF1 - valueS1) < 0)
	{

		cout << "Subtraction: " << endl;
		sumList.writeFunc((((valueF1 + 10) - valueS1)), &sumList.out5, &sumList);
		
		bit = 1;
	}
	else {
		cout << "Subtraction: " << endl;
		sumList.writeFunc(((valueF1 - valueS1)), &sumList.out5, &sumList);
		bit = 0;
	}

	if ((valueF2 - valueS2 - bit) < 0)
	{
		cout << "Subtraction: " << endl;
		sumList.writeFunc((((valueF2 + 10) - valueS2 - bit)), &sumList.out4, &sumList);
		
		bit = 1;
	}
	else {
		cout << "Subtraction: " << endl;
		sumList.writeFunc(((valueF2 - valueS2 - bit)), &sumList.out4, &sumList);
		bit = 0;
	}

	if ((valueF3 - valueS3 - bit) < 0) {

		cout << "Subtraction: " << endl;
		sumList.writeFunc((((valueF3 + 10) - valueS3 - bit)), &sumList.out3, &sumList);
		
		bit = 1;
	}
	else {
		cout << "Subtraction: " << endl;
		sumList.writeFunc(((valueF3 - valueS3 - bit)), &sumList.out3, &sumList);
		bit = 0;
	}

	if ((valueF4 - valueS4 - bit) < 0) {
		cout << "Subtraction: " << endl;
		sumList.writeFunc((((valueF4 + 10) - valueS4 - bit)), &sumList.out2, &sumList);
		
		bit = 1;
	}
	else {
		cout << "Subtraction: " << endl;
		sumList.writeFunc(((valueF4 - valueS4 - bit)), &sumList.out2, &sumList);
		bit = 0;
	}

	if ((valueF5 - valueS5 - bit) < 0) {
		cout << "Subtraction: " << endl;
		sumList.writeFunc((((valueF5 + 10) - valueS5 - bit)), &sumList.out1, &sumList);
		
		bit = 1;
	}
	else {
		cout << "Subtraction: " << endl;
		sumList.writeFunc(((valueF5 - valueS5 - bit)), &sumList.out1, &sumList);
		bit = 0;
	}

	cout << "Different method for subtraction: " << first->no - second->no << endl;
	printFunc(&sumList);

}

void inputNumber::writeFunc(int number, SinglyLinkedList* sumList, inputNumber* input) {

	SinglyNode* templNode = sumList->head;

	
	inputNumber* temp= input; //bunu kullanmayıp temp yerine &input da olurdu.

	cout << "------------------" << endl;
	_getch();
	system("cls");
	printFunc(temp);
	cout << "------------------" << endl;

	if (number >= 5)
	{
		templNode->score = 1;

		cout << "------------------" << endl;
		_getch();
		system("cls");
		printFunc(temp);
		cout << "------------------" << endl;


		templNode = templNode->next;
	
		int counterTemp = number - 5;

		while (((counterTemp) >= 1) && (templNode != NULL))
		{
			counterTemp--;
			templNode->score = 1;
			
			cout << "------------------" << endl;			
			_getch();
			system("cls");
			printFunc(temp);
			_getch();
			cout << "------------------" << endl;

			templNode = templNode->next;

		}
	}

	else {

		int counterTemp = number;

		cout << "------------------" << endl;
		_getch();
		system("cls");
		printFunc(temp);
		cout << "------------------" << endl;

		while (((counterTemp) >= 1) && (templNode != NULL))
		{

			cout << "------------------" << endl;
			_getch();
			system("cls");
			printFunc(temp);
			_getch();
			cout << "------------------" << endl;
			
			counterTemp--;
			templNode->next->score = 1;

			templNode = templNode->next;

		}

	}

}

int inputNumber::getStep() {

	return stepTemp;
}

int inputNumber::getValue(int step) {


	int temp = no;

	int y = 0;
	for (int i = 1; i <= step; i++)
	{

		y = temp % 10;

		temp /= 10;

	}


	return y;
}

void inputNumber::write() {

	SinglyNode* templList = list.head;

	SinglyNode* arrrayTemp[5] = { out1.head, out2.head, out3.head, out4.head, out5.head };

	int arrayCounter = (5 - stepTemp);

	int steps = stepTemp;


	while ((templList != NULL))
	{
		if (templList->score >= 5)
		{
			arrrayTemp[arrayCounter]->score = 1;

			arrrayTemp[arrayCounter] = arrrayTemp[arrayCounter]->next;

			int counterTemp = templList->score - 5;

			while (((counterTemp) >= 1) && (arrrayTemp[arrayCounter] != NULL))
			{
				counterTemp--;
				arrrayTemp[arrayCounter]->score = 1;


				arrrayTemp[arrayCounter] = arrrayTemp[arrayCounter]->next;

			}
		}

		else {

			int counterTemp = templList->score;

			while (((counterTemp) >= 1) && (arrrayTemp[arrayCounter] != NULL))
			{
				counterTemp--;
				arrrayTemp[arrayCounter]->next->score = 1;

				arrrayTemp[arrayCounter] = arrrayTemp[arrayCounter]->next;

			}

		}


		templList = templList->next;
		arrayCounter++;

	}


}

inputNumber::inputNumber(int number) {


	no = number;


	int temp1, step = 0;
	temp1 = number;

	while (temp1 >= 1)
	{
		temp1 /= 10;
		step++;
	}

	stepTemp = step;


	int temp2 = number;


	int steps = step;
	while (steps >= 1)
	{

		int y = temp2 % 10;
		//cout << "Number " << (((step - x) - step) * (-1)) << ": " << y << endl;
		//string template1 = "Number "  + to_string(((step - x) - step) * (-1)) ;

		string template1 = "Number " + to_string(steps);
		
		list.addFront(template1, y);

		temp2 /= 10;

		steps--;
	}

	int counter2 = 1;

	out1.addFront(to_string(5), 0);
	out2.addFront(to_string(5), 0);
	out3.addFront(to_string(5), 0);
	out4.addFront(to_string(5), 0);
	out5.addFront(to_string(5), 0);



	while (counter2 <= 4)
	{
		out1.addBack(to_string(1), 0);
		out2.addBack(to_string(1), 0);
		out3.addBack(to_string(1), 0);
		out4.addBack(to_string(1), 0);
		out5.addBack(to_string(1), 0);



		counter2++;
	}



	write();

	cout << endl;


	cout << "5" << "\t" << out1.head->score << "\t" << out2.head->score << "\t" << out3.head->score << "\t" << out4.head->score << "\t" << out5.head->score << endl;
	cout << "1" << "\t" << out1.head->next->score << "\t" << out2.head->next->score << "\t" << out3.head->next->score << "\t" << out4.head->next->score << "\t" << out5.head->next->score << endl;
	cout << "1" << "\t" << out1.head->next->next->score << "\t" << out2.head->next->next->score << "\t" << out3.head->next->next->score << "\t" << out4.head->next->next->score << "\t" << out5.head->next->next->score << endl;
	cout << "1" << "\t" << out1.head->next->next->next->score << "\t" << out2.head->next->next->next->score << "\t" << out3.head->next->next->next->score << "\t" << out4.head->next->next->next->score << "\t" << out5.head->next->next->next->score << endl;
	cout << "1" << "\t" << out1.head->next->next->next->next->score << "\t" << out2.head->next->next->next->next->score << "\t" << out3.head->next->next->next->next->score << "\t" << out4.head->next->next->next->next->score << "\t" << out5.head->next->next->next->next->score << endl << endl;


}

void inputNumber::sumFunction(inputNumber* first, inputNumber* second) {

	int fNo = first->no;
	int sNo = second->no;

	if (fNo >= sNo)
	{
		valueF1 = first->getValue(1);
		valueF2 = first->getValue(2);
		valueF3 = first->getValue(3); //1 birler, 2 onlar, 3 yüzler
		valueF4 = first->getValue(4);
		valueF5 = first->getValue(5);

		valueS1 = second->getValue(1);
		valueS2 = second->getValue(2);
		valueS3 = second->getValue(3);
		valueS4 = second->getValue(4);
		valueS5 = second->getValue(5);
	}
	else {
		valueF1 = second->getValue(1);
		valueF2 = second->getValue(2);
		valueF3 = second->getValue(3); //1 birler, 2 onlar, 3 yüzler
		valueF4 = second->getValue(4);
		valueF5 = second->getValue(5);

		valueS1 = first->getValue(1);
		valueS2 = first->getValue(2);
		valueS3 = first->getValue(3);
		valueS4 = first->getValue(4);
		valueS5 = first->getValue(5);
	}

	inputNumber sumList;

	sumList.setList(&sumList);


	//Different method for sum.
	int carry = 0;
	if ((valueF1 + valueS1) < 10)
	{
		cout << "Sum: " << endl;
		sumList.writeFunc((valueF1 + valueS1), &sumList.out5, &sumList);
		carry = 0;
	}
	else {
		cout << "Sum: " << endl;
		sumList.writeFunc(((valueF1 + valueS1) % 10), &sumList.out5, &sumList);
		carry = 1;
	}

	if ((valueF2 + valueS2 + carry) < 10)
	{
		cout << "Sum: " << endl;
		sumList.writeFunc((valueF2 + valueS2 + carry), &sumList.out4, &sumList);
		carry = 0;
	}
	else {
		cout << "Sum: " << endl;
		sumList.writeFunc(((valueF2 + valueS2 + carry) % 10), &sumList.out4, &sumList);
		carry = 1;
	}

	if ((valueF3 + valueS3 + carry) < 10) {
		cout << "Sum: " << endl;
		sumList.writeFunc((valueF3 + valueS3 + carry), &sumList.out3, &sumList);
		carry = 0;
	}
	else {
		cout << "Sum: " << endl;
		sumList.writeFunc(((valueF3 + valueS3 + carry) % 10), &sumList.out3, &sumList);
		carry = 1;
	}

	if ((valueF4 + valueS4 + carry) < 10) {
		cout << "Sum: " << endl;
		sumList.writeFunc((valueF4 + valueS4 + carry), &sumList.out2, &sumList);
		carry = 0;
	}
	else {
		cout << "Sum: " << endl;
		sumList.writeFunc(((valueF4 + valueS4 + carry) % 10), &sumList.out2, &sumList);
		carry = 1;
	}

	if ((valueF5 + valueS5 + carry) < 10) {
		cout << "Sum: " << endl;
		sumList.writeFunc((valueF5 + valueS5 + carry), &sumList.out1, &sumList);
		carry = 0;
	}
	else {
		cout << "Sum: " << endl;
		sumList.writeFunc(((valueF5 + valueS5 + carry) % 10), &sumList.out1, &sumList);
		carry = 1;
	}


	cout << "Different method for sum: "<< fNo + sNo << endl;
	printFunc(&sumList);
}


int main()
{	
	int first = 1, second = 1;

	cout << "first number:";
	cin >> first;

	inputNumber inputFirst(first);

	cout << "-----------------" << endl;

	cout << "second number:";
	cin >> second;

	inputNumber inputSecond(second);

	cout << "-----------------" << endl;


	string mString = to_string(first * second);
	int mSize = (int)(mString.size());

	string sString = to_string(first + second);
	int sSize = (int)(sString.size());
	
	string dString = to_string(first / second);
	int dSize = (int)(dString.size());

	string subString = to_string(first - second);
	int subSize = (int)(subString.size());

	//------------------------------------------------

	//different methods
	//------------------------------------------------
Menu:
	int action=0;
	cout << "Choose action: " << endl;
	cout << "Press 1 for +"<<endl;
	cout << "Press 2 for -" << endl;
	cout << "Press 3 for *" << endl;
	cout << "Press 4 for /" << endl;
	cin >> action;

	inputNumber showSum;
	inputNumber showSubtraction;
	inputNumber showMulti;
	inputNumber showDivision;

	switch (action)
	{
	case 1:
		
		if (sSize > 5) {
			cout << "Error! The output of sum can have a maximum of 5 digits." << endl << endl;
		}
		else {

			showSum.sumFunction(&inputFirst, &inputSecond);
		}		
		goto Menu;
		break;
	case 2:
		if (subSize > 5) {
			cout << "Error! The output of subtraction can have a maximum of 5 digits." << endl << endl;
		}
		else {

			showSubtraction.subtractionFunction(&inputFirst, &inputSecond);
		}		
		goto Menu;
		break;
	case 3:
		if (mSize > 5) {
			cout << "Error! The output of multiplication can have a maximum of 5 digits." << endl << endl;
		}
		else {

			showMulti.multiplicationFunction(&inputFirst, &inputSecond);
		}
		goto Menu;
		break;
	case 4:
		if (dSize > 5) {
			cout << "Error! The output of division can have a maximum of 5 digits." << endl << endl;
		}
		else {

			showDivision.divisionFunction(&inputFirst, &inputSecond);
		}		
		goto Menu;
		break;


	default:
		
		break;
	}
	
	

	cout << "-----------------" << endl << endl;

	//------------------------------------------------

	//easy methods
	/*cout << "Easy Methods: " << endl;
	cout << "Sum: " << first + second;
	inputNumber sumClass(first + second);
	cout << endl;
	cout << "-----------------" << endl;


	cout << "Subtraction: " << first - second;
	if (first >= second)
	{
		inputNumber subtractionClass(first - second);
	}
	else {
		inputNumber subtractionClass(second - first);
	}
	cout << endl;
	cout << "-----------------" << endl;


	cout << "Multiplication: " << first * second << endl;;	
	if (mSize > 5)
	{
		cout << "Error! The output of multiplication can have a maximum of 5 digits." << endl << endl;
		cout << "-----------------" << endl;
	}
	else {
		inputNumber multiplicationClass(first * second);
		cout << endl;
		cout << "-----------------" << endl;
	}

	double div = (double)first / (double)second;
	cout << "Divison: " << div;
	inputNumber divisonClass(first / second);
	cout << endl;*/

}