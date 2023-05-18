#include "configreader.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "iniparser.h"
#include "dictionary.h"

#ifdef __cplusplus
}
#endif // __cplusplus

void ConfigReader_init(ConfigReader_t *self)
{
    if(NULL == self)
        return;

    self->dict = NULL;
}

void ConfigReader_free(ConfigReader_t *self)
{
    if(NULL == self)
        return;

    if(NULL != self->dict)
    {
        iniparser_freedict(self->dict);
        self->dict = NULL;
    }
}

int ConfigReader_load(ConfigReader_t *self, const char *fileName)
{
    if(NULL == self)
        return 1;

    if (NULL != self->dict)
    {
        iniparser_freedict(self->dict);
        self->dict = NULL;
    }

    self->dict = iniparser_load(fileName);

    if (NULL == self->dict)
    {
        printf("can not open file: %s", fileName);
        return 1;
    }

    return 0;
}


const std::string get_mail_addr(ConfigReader_t *self)
{
    const char *str = NULL;
    char invalidStr[2] = {0};

    if(NULL == self)
        return NULL;
    if(NULL == self->dict)
        return NULL;

    str = iniparser_getstring(self->dict, "CONF_HDFSTSCHK:mail-addr", invalidStr);

    return str;
}
