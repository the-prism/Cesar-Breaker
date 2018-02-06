#pragma once

class Decryptor
{
public:
	Decryptor();
	~Decryptor();
	void SetMessage(std::string input);
	void DecodeMessage();
private:
	std::string encrypted_message;
	int key;
	std::string decrypted_message;
	int counter[26];
};

