#include	<memory.h>
#include	<string.h>
#include 	<stdio.h>
#include	<varargs.h>
#include 	<time.h>
#include 	<sys/ipc.h>
#include 	<sys/msg.h>
#include 	<curses.h>


/**********************************************************************/
extern int date_gettoday(char *fmt, char *strtime);
/**********************************************/
/*��  �ܣ����ݸ�ʽȡ�õ�ǰ����ʱ����ַ�����	      */
/*��  �룺fmt-��ʽ:	CC - ����	      */
/*		  	YY - ��		      */
/*		  	MM - �·�	      */
/*		  	DD - ��		      */
/*		  	HH - Сʱ	      */
/*		  	MI - ����	      */
/*		  	SS - ����	      */
/*��  ����strtime-�����ַ�����		      */
/*����ֵ��TRUE-�ɹ���FALSE-���ɹ�;		      */
/**********************************************/

extern int date_get_gwtime(char *fmt, char *strtime);
/**********************************************/
/*��  �ܣ����ݸ�ʽȡ�õ�ǰ������������ʱ����ַ�����*/
/*��  �룺fmt-��ʽ:	CC - ����	      */
/*		  	YY - ��		      */
/*		  	MM - �·�	      */
/*		  	DD - ��		      */
/*		  	HH - Сʱ	      */
/*		  	MI - ����	      */
/*		  	SS - ����	      */
/*��  ����strtime-�����ַ�����		      */
/*����ֵ��TRUE-�ɹ���FALSE-���ɹ�;		      */
/**********************************************/

extern int date_verify(char *strfmt, char *strbuf);
/**********************************************/
/*��  �ܣ�У���ַ��������Ƿ�Ϸ���		      */
/*��  �룺strfmt-"CCYYMMDD", 		      */
/*	 strbuf-�����ַ�����		      */
/*����ֵ��TRUE-�Ϸ���FALSE-���Ϸ�;		      */
/**********************************************/

/**********************************************************************/
extern char * del_ablank(char * str);
/********************************/
/*��  �ܣ�ɾ���ַ���ǰ�������Ŀո�*/
/*��  �룺str	- ��Ҫ������ַ���*/
/*��  ����str	- �������ַ���  */
/*��  �أ��������ַ�����ָ�룩   */
/********************************/


extern char * str_limitlen(char * str, char ch, int flag, int len);
/**********************************************/
/*��  �ܣ����ַ����ø����ַ����뵽�����ĳ��ȣ�     */
/*��  �룺str	- ��Ҫ������ַ���	      */
/*	 ch 	- ���������ַ�		      */
/*	 flag 	- 1��ǰ�油�룻		      */
/*	 	- 0: ���油��		      */
/*	 len	- �����ĳ���		      */
/*��  ����str-�������ַ�����		      */
/*����ֵ���������ַ�����ָ�룩;		      */
/**********************************************/

struct ISO8583 {
	short bit_flag;        
	char  data_name[37];   
	short length;          
	short attribute;       
	short variable_flag;   
	short length_in_byte;  
	char  *data;           
};

extern struct ISO8583 master[128];
extern struct ISO8583 visa[128];
extern int unpack_master_8583(char *buf);
extern int visa_master_8583(char *buf);


#define		QUEUESIZE		8192
typedef struct queue	QUEUE;
struct queue {
	long	type;
	char	text[QUEUESIZE];
};

#define WB_SEND_QUEUE	0x11111111
#define WB_RECV_QUEUE	0x22222222
#define WB_MANG_QUEUE	0x33333333
#define MONITOR_QUEUE	0x2002

extern int send_queue(key_t key, char *msg, size_t msglen, long msgtype, int msgflg);
/********************************************************/
/*	����:	����Ϣ���з�����Ϣ				*/
/*	����:						*/
/*		key_t	:	��Ϣ���м�ֵ		*/
/*		char *	:	��Ϣ��ŵ�ַ		*/
/*		size_t	:	��Ϣ����			*/
/*		long	:	��Ϣ��������(����>0)	*/
/*		int	:	IPC_NOWAIT		*/
/*				0			*/
/*	����:						*/
/*		TRUE	:	�ɹ�			*/
/*		FALSE	:	ʧ��			*/
/********************************************************/
extern int recv_queue(key_t key, char *msg, long *rettype, long msgtype, int msgflg);
/***********************************************************/
/*	����:	����Ϣ���н�����Ϣ				   */
/*	����:						   */
/*		key_t	:	��Ϣ���м�ֵ		   */
/*		char *	:	��Ϣ��ŵ�ַ		   */
/*		long 	:	��Ϣ��������		   */
/*				=0��	�Ӷ����н��յ�һ����Ϣ*/
/*				>0:	������Ϣ������ͬ����Ϣ*/
/*		int	:	IPC_NOWAIT		   */
/*				0			    */
/*	����:						    */
/*	�����	long *	��	���յ�����Ϣ����		    */
/*		>0	:	�ɹ�(ֵΪ��Ϣ����)	    */
/*		FALSE	:	ʧ��			    */
/************************************************************/
