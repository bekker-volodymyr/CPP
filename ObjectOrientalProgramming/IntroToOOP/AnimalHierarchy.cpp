class Animal {
protected:
	char* nickname;
	int age;
public:
	char* GetNickname() {
		return nickname;
	}
	int GetAge() {
		return age;
	}
	// Setters
	void SetNickname(char* name) {
		if (name != nullptr) {
			nickname = name;
		}
	}
	void SetAge(int a) {
		if (a > 0) {
			age = a;
		}
	}
};

class Dog : public Animal
{
private:
	char* breed;
public:
	char* GetBreed() {
		return breed;
	}
	void SetBreed(char* b) {
		breed = b;
	}
};