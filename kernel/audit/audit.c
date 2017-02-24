#include <stdio.h>
#include <unistd.h>
#include <libaudit.h>

int main() {
    
    int audit_d = audit_open();
    if ( audit_d < 0 )
    {
        printf("Audit open error!\n");
        return 1;
    }
    
    const char *message = "love_xiaoqi";
    if (audit_log_user_message( audit_d, AUDIT_USER, message, 
                                NULL, NULL, NULL, 1) < 0)
    {
        printf("The error message is not sent successfully!\n");
        close(audit_d);
        return 2;
    }
    close(audit_d);
    
    return 0;
}
