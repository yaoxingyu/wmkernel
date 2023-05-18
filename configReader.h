#ifndef CONFIGREADER_H
#define CONFIGREADER_H
#include <string>


typedef struct ConfigReader
{
    struct _dictionary_ *dict;
} ConfigReader_t;


/**
 * @brief ConfigReader_init
 * init function, must call this function before call other
 * functions which operate this object.
 *
 * @param self
 * object to operate, cannot be null.
 */
void ConfigReader_init(ConfigReader_t *self);

/**
 * @brief ConfigReader_free
 * free function, must call this function before destory
 * this object.
 *
 * @param self
 * object to operate, cannot be null.
 */
void ConfigReader_free(ConfigReader_t *self);

/**
 * @brief ConfigReader_load
 * load config from file
 *
 * @param self
 * object to operate, cannot be null.
 *
 * @param fileName
 * config file path, example: /home/etc/example.ini
 *
 * @return
 * 0: success; 1: false
 */
int ConfigReader_load(ConfigReader_t *self, const char *fileName);


const std::string get_mail_addr(ConfigReader_t *self);
