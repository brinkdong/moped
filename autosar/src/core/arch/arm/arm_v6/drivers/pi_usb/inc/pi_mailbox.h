/*
 * pi_mailbox.h
 *
 *  Created on: 2013-11-18
 *      Author: Zhang Shuzhou
 */

#ifndef PI_MAILBOX_H_
#define PI_MAILBOX_H_

#include <semaphore.h>
#include <usb_stddef.h>

#define MAILBOX_FREE     0
#define MAILBOX_ALLOC    1
#define NMAILBOX         15
/**
 * Defines what an entry in the mailbox table looks like.
 */
struct mbox
{
    semaphore sender;           /**< count of free spaces in mailbox    */
    semaphore receiver;         /**< count of messages ready to recieve */
    uint max;                   /**< max #of messages mailbox can hold  */
    uint count;                 /**< #of msgs currently in mailbox      */
    uint start;                 /**< index into buffer of first msg     */
    uchar state;                /**< state of the mailbox               */
    int *msgs;                  /**< message queue for the mailbox      */
};

typedef uint mailbox;

extern semaphore mboxtabsem;

extern struct mbox mboxtab[];

/* Mailbox function prototypes */
syscall mailboxAlloc(uint);
syscall mailboxCount(mailbox);
syscall mailboxFree(mailbox);
syscall mailboxInit(void);
syscall mailboxReceive(mailbox);
syscall mailboxSend(mailbox, int);




#endif /* PI_MAILBOX_H_ */
