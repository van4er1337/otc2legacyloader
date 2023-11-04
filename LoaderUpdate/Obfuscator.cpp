#include "includes.h"

void obfuscateFile(const char* filename) {
    // Чтение содержимого файла
    std::ifstream inFile(filename, std::ios::binary);
    std::vector<unsigned char> fileData((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();

    // Генерация ключа и вектора инициализации
    unsigned char encryptionKey[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    // Здесь должна быть ваша логика по созданию ключа и IV

    // Настройка структур для шифрования
    AES_KEY aesKey;
    AES_set_encrypt_key(encryptionKey, 128, &aesKey);

    // Шифрование данных
    unsigned char encryptedData[fileData.size()];
    for (size_t i = 0; i < fileData.size(); i += AES_BLOCK_SIZE) {
        AES_cbc_encrypt(&fileData[i], &encryptedData[i], AES_BLOCK_SIZE, &aesKey, iv, AES_ENCRYPT);
    }

    // Запись зашифрованных данных обратно в файл
    std::ofstream outFile(filename, std::ios::binary | std::ios::trunc);
    outFile.write(reinterpret_cast<char*>(encryptedData), fileData.size());
    outFile.close();
}
