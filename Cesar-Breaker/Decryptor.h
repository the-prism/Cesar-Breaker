#pragma once

class Decryptor
{
public:
	Decryptor();
	~Decryptor();
	void SetMessage(std::string* input); //Reference ms ^ ?
	void DecodeMessage();
private:
	std::string encrypted_message;
	int key;
	std::string decrypted_message;
	char* counter; //TODO: C++ array

};

