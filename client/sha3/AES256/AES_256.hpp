#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <boost/format.hpp>

#define defFILE (1)
#define defFILENAME (0)

void printf_matrix(unsigned char A[4][4]);

long filesize(FILE *file);
void get_new_block(unsigned char State[4][4], FILE *file);
void output_block(unsigned char State[4][4], FILE *encr_file);

//����������� ������� ������� � ������� �����
unsigned long get_dword(unsigned char A[4][4], int index);
unsigned long get_dword_for_256(unsigned char A[4][8], int index);
//����������� ������ ������� � ������� �����
unsigned long get_string_dword(unsigned char A[4][4], int index);

FILE* complement_file(FILE *file, int file_size, char final_fname[256], int *error);

unsigned char multiply(unsigned char a, unsigned char b);
// dword � �������
void dword_to_matrix(unsigned long dword, unsigned char A[4][4], int index);
// dword � ������
void dword_string_to_matrix(unsigned long dword, unsigned char A[4][4], int index);
//���������� �����
void encrypt_block(unsigned char State[4][4], unsigned long RoundKeys[64]);
//����������� �����
void decrypt_block(unsigned char State[4][4], unsigned long RoundKeys[64]);

//����������� ����� ������.
void RotWord(unsigned long *dword);

//������ ������ ������� State S-Box
void SubBytes(unsigned char State[4][4]);
//������ ������ ������� State InvS-Box
void InvSubBytes(unsigned char State[4][4]);

//������ ������ 4 �������� �����  S-Box
void SubWord(unsigned long  *dword);
//������ ������ 4 �������� �����  InvS-Box
void InvSubWord(unsigned long  *dword);

//��������� ������� ������� State �� ������������� ������� C
void MixColumns(unsigned char State[4][4]);
//��������� ������� ������� State �� ������������� ������� C
void InvMixColumns(unsigned char State[4][4]);

void InvShiftRows(unsigned char State[4][4]);

void file_copy(char *filename, char *file_to_copy);

unsigned long g(unsigned long key, int round_num);
//���������� �������� ����� �� 10 �������
//void Key_Expansion(unsigned char InputKey[4][4], unsigned long RoundKeys[44]);
void Key_Expansion(unsigned char InputKey[4][8], unsigned long RoundKeys[64]);
// State XOR RoundKey
void AddRoundKey(unsigned char State[4][4], unsigned long RoundKeys[64], int num_key);

//�������� ������ �����, �������� ��������� ��������������� �����.
void delete_excess_zeroes(FILE *decr_file, char final_fname[], int *error);

//���������� ������ � ������� AES-128
void encrypt(char final_fname[256], unsigned char InputKey[4][8], int *error, int flag);
//������������� ������ � ������� AES-128
void decrypt(char file_fname[256], unsigned char InputKey[4][8], int *error, int flag);
std::string uniq_filename(int *error);
char *string_to_char(std::string str);
