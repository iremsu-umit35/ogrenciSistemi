/*
## student management system

This //commit adds the implementation for a student management system using a doubly linked list.The functionalities include :

-**Student Creation * *: Adds a new student node with GPA and name.
- **Insertions * *:
	-`insertFront()`: Adds a student to the front of the list.
	- `insertAfter()`: Adds a student after a specified node.
	- `insertEnd()`: Adds a student to the end of the list.
	- **Deletion * *: Removes a specific student node from the list.
	- **Display * *: Prints out all student details in the list.
	- **GPA Calculation * *: Calculates and displays the average GPA of all students.
	- **Search * *: Finds and displays a student with a specified name.

	* *Notes : **

	-`findFrequencyOfName` function is incomplete; it does not print the frequency of the name.
	- `searchStudent` function should handle cases where the student is not found more robustly.

	This commit also includes various test cases to ensure the functionalities work as intended.

	
	
	
	## Öğrenci Yönetim Sistemi

	Bu commit, çift bağlı liste kullanarak bir öğrenci yönetim sistemi uygulamasını ekler. İşlevler şunları içerir:

	- **Öğrenci Oluşturma**: GPA ve isimle yeni bir öğrenci düğümü ekler.
	- **Ekleme İşlemleri**:
	  - `insertFront()`: Öğrenciyi listenin başına ekler.
	  - `insertAfter()`: Belirtilen bir düğümden sonra öğrenci ekler.
	  - `insertEnd()`: Öğrenciyi listenin sonuna ekler.
	- **Silme**: Belirli bir öğrenci düğümünü listeden çıkarır.
	- **Görüntüleme**: Listede bulunan tüm öğrenci detaylarını ekrana yazdırır.
	- **GPA Hesaplama**: Tüm öğrencilerin ortalama GPA'sını hesaplar ve ekrana yazdırır.
	- **Arama**: Belirtilen isme sahip öğrenciyi bulur ve bilgilerini ekrana yazdırır.

	**Notlar:**

	- `findFrequencyOfName` fonksiyonu tamamlanmamış; ismin frekansını yazdırmıyor.
	- `searchStudent` fonksiyonu, öğrencinin bulunamadığı durumları daha sağlam bir şekilde ele almalıdır.

	Bu commit ayrıca işlevlerin doğru çalıştığını doğrulamak için çeşitli test vakalarını içerir.
	*/


// ogrenciSistemi.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <string>
#include <iostream>
using namespace std;


struct student
{
	int gpa; //öğrencinin not ortalamasını
	string name; //öğrencinin adını
	struct student* next = NULL; //bir sonraki ve bir 
	struct student* prev = NULL; //önceki öğrenciye işaret eder
};


//Bu fonksiyon, yeni bir öğrenci düğümü oluşturur
struct student* createStudent(int gpa, string name)
{
	struct student* newNode = new student;
	newNode->gpa = gpa;
	newNode->name = name;
	return newNode;
};

//Listedeki belirli bir ismin kaç kez geçtiğini bulur ve bu sayıyı ekrana yazdırır
void findFrequencyOfName(struct student* head, string name) {
	int nName = 0;
	while (head != NULL) {
		if (head->name == name) {
			nName += 1;
		}
		head = head->next;
	}
	cout << "Number of students with this name:  " << endl;
}

// listenin başına yeni bir düğüm eklemek
void insertFront(struct student** head, int gpa, string name) {
	student* newNode = createStudent(gpa, name);
	newNode->next = (*head);
	newNode->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = newNode;
	(*head) = newNode;
}

//elirli bir düğümden sonra yeni bir düğüm eklemek
void insertAfter(struct student*  prev_node, int gpa, string name) {
	if (prev_node == NULL) {
		cout << "The previous node cannot be null";
		return;
	}

	student* newNode = createStudent(gpa, name);
	newNode->next = prev_node->next;
	prev_node->next = newNode;
	newNode->prev = prev_node;

	if (newNode->next != NULL)
		newNode->next->prev = newNode;
}

//istenin sonuna yeni bir düğüm eklemek.
void insertEnd(struct student** head, int gpa, string name) {
	student* newNode = createStudent(gpa, name);
	newNode->next = NULL;
	struct student* temp = *head;

	if (*head == NULL) {
		newNode->prev = NULL;
		*head = newNode;
		return;
	}

	while (temp->next != NULL)
		temp = temp -> next;
	temp->next = newNode;
	newNode->prev = temp;
}

//belirtilen düğümü listeden siler.
void deleteNode(struct student** head, struct student* del_node) {

	if (*head == NULL || del_node == NULL)
		return;
	if (*head == del_node)
		*head = del_node->next;
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;
	if (del_node->prev != NULL)
		del_node->prev->next = del_node->next;
	delete del_node;
}

//listenin tamamını ekrana yazdırır
void displayList(struct student* head) {

	while (head != NULL) {
		cout << head->gpa << " -> " << head->name << endl;
		head = head->next;
	}
	if (head == NULL)
		cout << "\nThe end of the double-bound list\n";
}


//listedeki tüm öğrencilerin GPA'larını toplayarak ortalamayı hesaplar ve ekrana yazdırır.
void calculatingAverageGPA(struct student* head) {
	double total = 0;
	int count = 0;

	while (head != NULL) {
		total += head->gpa;
		count++;
		head = head->next;
	}
	if (count > 0)
		cout << "Average GPA:  " << total / count << endl;
	cout << "\nThe end of the double-bound list\n";
}


//isme göre bir öğrenciyi arar ve bulursa bilgilerini ekrana yazdırır.
void searchStudent(struct student* head, string name) {
	int found = 0;
	while (head != NULL) {
		if (head->name == name) {
			found = 1;
			cout << "I found a student with this name: " << head->name << " her/his GPA is: " << head->gpa << endl;
			break;
		}
		head = head->next;
	}
	if (found == 0) {
		cout << name << " the named student has not been found." << endl;
}




	int main();
{
	struct student* head = NULL;


	insertEnd(&head, 5, "Ali");
	insertFront(&head, 1, "Ahmet");
	insertFront(&head, 6, "Elif");
	insertEnd(&head, 9, "Veli");
	insertAfter(head, 11, "Ayse");
	insertAfter(head->next, 15, "Mehmet");

	displayList(head);
	searchStudent(head, "Elif");
	calculatingAverageGPA(head);
	deleteNode(&head, head->next->next->next->next->next);

	displayList(head);
}
