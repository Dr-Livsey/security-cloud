#include <iostream>
#include <string>
#include <fstream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem.hpp>

#include "DiffieHelman_server/DH_server.hpp"


typedef unsigned long long ull;

void recieve_answer(socket_ptr sock, uint256_t *command_hash, uint256_t *answer, uint256_t key);
void send_request(socket_ptr sock, uint256_t command, uint256_t auth_hash, uint256_t key);

/*������ ���������� � �����.*/
char *read_fileinfo(socket_ptr sock, ull *file_size);
/*�������� �����*/
void create_file(char *directory, char *data, ull fsize, char *filename);
/*������� ����� �� �������*/
void recieve_handler(socket_ptr sock);
/*��������� ������������� ���.*/
char *recieve_encr_filename(socket_ptr sock, uint256_t key);
/*������ �������*/
void client_session(socket_ptr sock);
/*��������� ��� �������� ����������*/
void connection_loop(socket_ptr sock);
/*�������������� � ��������� ������ � ������ ������������*/
void authentification(uint256_t command_hash, uint256_t auth_hash, socket_ptr sock);
/*���������� ������� �� ��� ������� � ������*/
void parse_pack(uint512_t pack, uint256_t *command_hash, uint256_t *info);
/*�������� �������*/
uint512_t make_pack(uint256_t command_hash, uint256_t info);
/*���������� ������ ������� � ��*/
void add_new_client(uint256_t command_hash, uint256_t auth_hash);

void create_folder(uint256_t hash);

/*�������� ����� �� �������*/
void recieve_file(socket_ptr sock, char *name_folder);
/*�������� ����� �������*/
void send_file(socket_ptr sock, char *name_folder, char *filename);
char *read_file(std::string client_path, ull *size);

void download_file(uint256_t command_hash, uint256_t auth_hash, socket_ptr sock);
void upload_file(uint256_t command_hash, uint256_t auth_hash, socket_ptr sock);
void delete_file(uint256_t command_hash, uint256_t auth_hash, socket_ptr sock);

char *hash_to_str(uint256_t hash);
char *str_to_hash(char *str, size_t size);
char *fname_to_hashstr(char *fname, size_t dsize);

/*������� ������ ������.*/
void get_filelist(uint256_t command_hash, uint256_t auth_hash, socket_ptr sock);

/*�������� ������������� ������� Id �� �������.*/
bool check_login_hash(char *hash_string, uint256_t command_hash, socket_ptr sock);

void rename_file(uint256_t command_hash, uint256_t auth_hash, socket_ptr sock);
void client_session(socket_ptr sock, socket_ptr sock1);
