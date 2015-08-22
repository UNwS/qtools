/** @mainpage QS/QSPY

- @ref rev_page_qspy
- @ref qspy_intro_sec
- @ref qspy_command
- @subpage qspy_human_format
- @subpage qspy_matlab
- @subpage qspy_mscgen

@section qspy_intro_sec Introduction

Quantum Spy&tm; (%QS) is a real-time tracing instrumentation built into the @ref overview "QP event-driven platform". %QS allows you to gain unprecedented visibility into your application by selectively logging almost all interesting events occurring within state machines, the framework, the kernel, and your application code. %QS event logging is minimally intrusive, offers precise time-stamping, sophisticated runtime filtering of events, and good data compression. %QS can be configured to send the real-time data out of the serial or Ethernet port of the target device, or even write the data to a file. %QS is described in Chapter 11 of the book @ref PSiCC2, Newnes 2008.

Every software tracing system consists of a target component and a host component. The host component for the Quantum Spy software tracing system is the <B>QSPY host application</B>. QSPY is a simple console application without any fancy GUI because its purpose is to provide only the QS data parsing, storing,and exporting to such powerful tools as <STRONG>MATLAB</STRONG> or GNU <STRONG>OCTAVE</STRONG>. QSPY has been designed from the ground up to be platform-neutral. The application is written in portable C++, and ports to Linux and Windows with various compilers are provided.

@image html qspy.jpg "A typical setup for collecting software trace data with QSPY"

QSPY is easily adaptable to various target-host communication links. Out of
the box, the QSPY host application supports serial (RS232), TCP/IP, and file
communication links. Adding other communication links is easy, because the
data link layer is clearly abstracted in a Hardware Abstraction Layer (HAL).
The QSPY application accepts several command-line parameters to configure all
target dependencies, such as pointer sizes, signal sizes, etc. This means that
the single QSPY host application can process data from any target 8-, 16-, or
32-bit.

QSPY provides a simple consolidated, human-readable textual output to the
screen. If the QS trace data contains dictionary trace records, QSPY applies
this symbolic information to output the provided identifiers for objects,
signals, and states. Otherwise, QSPY outputs the hexadecimal values of various
pointers and signals. (See Section @ref qspy_human_format).

Finally, QSPY can export the trace data in the matrix format readable by
MATLAB/Octave. Special MATLAB script to import QSPY trace data to MATLAB/Octave
is provided. Once the data is available in MATLAB matrices, it can be conveniently
manipulated and visualized with this powerful tool. (See Section @ref
qspy_matlab and @ref qspy_mscgen).

<HR>
@section qspy_command QSPY Command-Line Parameters

The QSPY host application is designed to work with all possible target CPUs
and data links, which requires a wide range of configurability. For example,
for any given target CPU the QSPY application must "know" the size of object
pointers, function pointers, event signals, timestamp size and so on. You
provide this information to QSPY by means of command-line parameters, which
are summarized in the following table:

<TABLE SUMMARY="QSPY parameters" cellSpacing=4 cellPadding=1 border=0
ALIGN="center" VALIGN="middle">
  <TR bgColor="#c8cedc">
    <TD><B>&nbsp;Option</B></TD>
    <TD><B>&nbsp;Example</B></TD>
    <TD><B>&nbsp;Default</B></TD>
    <TD><B>&nbsp;Must match QP macro@n (QP port header file)</B></TD>
    <TD><B>&nbsp;Comments</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>-h</TD>
    <TD>-h</TD>
    <TD></TD>
    <TD></TD>
    <TD>Help. Prints the summary of options</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-q</TD>
    <TD>-q</TD>
    <TD></TD>
    <TD></TD>
    <TD>Quiet mode (no stdout output)</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>-v</TD>
    <TD>-v 4.1</TD>
    <TD>4.2</TD>
    <TD></TD>
    <TD>Compatibility with QS version</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-o</TD>
    <TD>-o qs.txt</TD>
    <TD></TD>
    <TD></TD>
    <TD>Produce output to the specified file</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>-s</TD>
    <TD>-s qs.spy</TD>
    <TD></TD>
    <TD></TD>
    <TD>Save the binary input to the specified file. Not compatible with -f
    </TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-m</TD>
    <TD>-m qs.mat</TD>
    <TD></TD>
    <TD></TD>
    <TD>Generates MATLAB/Octave output to the specified file</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-g</TD>
    <TD>-g qs.msc</TD>
    <TD></TD>
    <TD></TD>
    <TD>Generates MscGen output to the specified file</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>-c</TD>
    <TD>-c COM2</TD>
    <TD>COM1</TD>
    <TD></TD>
    <TD>COM port selection. Not compatible with -t, -p, -f</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-b</TD>
    <TD>-b 38400</TD>
    <TD>115200</TD>
    <TD></TD>
    <TD>Baud rate selection. Not compatible with -t, -p, -f</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>-t</TD>
    <TD>-t</TD>
    <TD></TD>
    <TD></TD>
    <TD>TCP/IP input selection. Not compatible with -c, -b, -f</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-p</TD>
    <TD>-p 6602</TD>
    <TD>6601</TD>
    <TD></TD>
    <TD>TCP/IP server port number. Not compatible with -c, -b, -f</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>-f</TD>
    <TD>-f qs.spy</TD>
    <TD></TD>
    <TD></TD>
    <TD>File input selection. Not compatible with -c, -b, -t, -p</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-T</TD>
    <TD>-T 2</TD>
    <TD>4</TD>
    <TD>@c QS_TIME_SIZE @n (qs_port.h)</TD>
    <TD>Time stamp size in bytes. Valid values: 1, 2, 4</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>-O</TD>
    <TD>-O 2</TD>
    <TD>4</TD>
    <TD>@c QS_OBJ_PTR_SIZE @n (qs_port.h)</TD>
    <TD>Object pointer size in bytes. Valid values: 1, 2, 4, 8</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-F</TD>
    <TD>-F 2</TD>
    <TD>4</TD>
    <TD>@c #QS_FUN_PTR_SIZE @n (qs_port.h)</TD>
    <TD>Function pointer size in bytes. Valid values: 1, 2, 4, 8</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>-S</TD>
    <TD>-S 1</TD>
    <TD>2</TD>
    <TD>@c #Q_SIGNAL_SIZE @n (qep_port.h)</TD>
    <TD>Signal size in bytes. Valid values: 1, 2, 4</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-E</TD>
    <TD>-E 1</TD>
    <TD>2</TD>
    <TD>@c #QF_EVENT_SIZ_SIZE @n (qf_port.h)</TD>
    <TD>Event-size size in bytes (i.e., the size of variables that hold
        event size). Valid values: 1, 2, 4</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>-Q</TD>
    <TD>-Q 1</TD>
    <TD>2</TD>
    <TD>@c #QF_EQUEUE_CTR_SIZE @n (qf_port.h)</TD>
    <TD>Queue counter size in bytes. Valid values 1, 2, 4</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-P</TD>
    <TD>-P 4</TD>
    <TD>2</TD>
    <TD>@c #QF_MPOOL_CTR_SIZE @n (qf_port.h)</TD>
    <TD>Pool counter size in bytes. Valid values: 1, 2, 4</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>-B</TD>
    <TD>-B 1</TD>
    <TD>2</TD>
    <TD>@c #QF_MPOOL_SIZ_SIZE @n (qf_port.h)</TD>
    <TD>Block size size in bytes. (i.e., the size of variables that hold
        memory block size). Valid values 1, 2, 4</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>-C</TD>
    <TD>-C 4</TD>
    <TD>2</TD>
    <TD>@c #QF_TIMEEVT_CTR_SIZE @n (qf_port.h)</TD>
    <TD>Time event counter size. Valid values: 1, 2, 4</TD>
  </TR>
</TABLE>


The QSPY host application is designed to work with all possible target CPUs
and data links, which requires a wide range of configurability. For example,
for any given target CPU the QSPY application must "know" the size of object
pointers, function pointers, event signals, timestamp size and so on. You
provide this information to QSPY by means of command-line parameters, which
are summarized in table above. Please note that the options are case sensitive.


Your main concern when invoking QSPY is to match exactly the target system you
are using. The fourth column of the table above lists the configuration macros
used by the target system as well as the platform-specific QP header files
where those macros are defined. You need to use the corresponding QSPY
command-line option only when the QP macro differs from the default. The
default values assumed by QSPY are consistent with the defaults used in QP.

@note When you do not match the QSPY host application with the QS target
component, the QSPY application will be unable to parse correctly the
mismatched trace records and will start generating the following errors:

@verbatim
     ********** 028: Error xx bytes unparsed
     ********** 014: Error -yy bytes unparsed
@endverbatim

The number in front of the error indicates the Record ID of the trace record
that could not be parsed.


------------------------------------------------------------------------------
@section qspy_licensing Licensing QSPY

The QSPY host application is licensed the same way as all other components of
the QP event-driven platform. See Section @ref licensing.

@image html logo_ql_TM.jpg
Copyright &copy; 2002-2015 Quantum Leaps, LLC. All Rights Reserved.@n
http://www.state-machine.com
*/

/**
@page qspy_human_format Human-Readable QSPY Output

The QSPY host application is just a simple console-type program without any
fancy user interface. QSPY application displays the trace data in a
human-readable textual format. The following listing shows fragments of such
a data log generated from the DOS/QK version of the DPP application.

@note The QSPY host application supports also exporting data to the powerful
MATLAB/Octave environment, as described in Section @ref qspy_matlab.

@verbatim
QSPY host application 4.2.00
Copyright (c) Quantum Leaps, LLC.
Mon Aug 01 17:38:23 2011

-T 4
-O 4
-F 4
-S 1
-E 2
-Q 1
-P 2
-B 2
-C 2

           Obj Dic: 16CA18D8->l_smlPoolSto
           Obj Dic: 16CA1900->l_tableQueueSto
           Obj Dic: 16CA1914->l_philoQueueSto[0]
. . . . . .
           EQ.INIT: Obj=l_tableQueueSto Len= 5
0000000000 AO.ADD : Active=16CA1CB8 Prio= 6
           Obj Dic: 16CA1CB8->&l_table
           Fun Dic: 141E0006->&QHsm_top
           Fun Dic: 12DA00C9->&Table_initial
           Fun Dic: 12DA020B->&Table_serving
           Sig Dic: 00000008,Obj=16CA1CB8 ->HUNGRY_SIG
0000000000 AO.SUB : Active=l_table Sig=DONE_SIG
0000000000 AO.SUB : Active=l_table Sig=TERMINATE_SIG
           Q_INIT : Obj=l_table Source=QHsm_top Target=Table_serving
0000000000 ==>Init: Obj=l_table New=Table_serving
0000070346 QF_isrE: IsrNest= 1, CurrPrio=255
           TICK   : Ctr=         1
0000070367 QF_isrX: IsrNest= 1, CurrPrio=255
0000135566 QF_isrE: IsrNest= 1, CurrPrio=255
           TICK   : Ctr=         2
0000135581 QF_isrX: IsrNest= 1, CurrPrio=255
. . . . .
0000461783 QF_isrE: IsrNest= 1, CurrPrio=255
           TICK   : Ctr=         7
           TE.ADRM: Obj=l_philo[1].timeEvt Act=l_philo[1]
0000461797 TE.POST: Obj=l_philo[1].timeEvt Sig=TIMEOUT_SIG Act=l_philo[1]
0000461808 AO.FIFO: Obj=l_philo[1] Evt(Sig=TIMEOUT_SIG, Pool=0, Ref= 0)
>          Queue(nUsed=  5, nMax=  5)
0000461824 QF_isrX: IsrNest= 1, CurrPrio=255
0000461836 AO.GETL: Active= l_philo[1] Evt(Sig=TIMEOUT_SIG, Pool=0, Ref= 0)
0000461850 NEW    : Evt(Sig=HUNGRY_SIG, size=    3)
0000461862 MP.GET : Obj=l_smlPoolSto nFree=   9 nMin=   9
0000461874 AO.FIFO: Obj=l_table Evt(Sig=HUNGRY_SIG, Pool=1, Ref= 0)
>          Queue(nUsed=  5, nMax=  5)
0000461886 AO.GETL: Active= l_table Evt(Sig=HUNGRY_SIG, Pool=1, Ref= 1)
0000461906 NEW    : Evt(Sig=EAT_SIG, size=    3)
@endverbatim

The QS trace log shown in the listing above contains quite detailed
information, because most QS records are enabled (are not blocked in the QS
filters). The following bullet items highlight the most interesting parts of
the trace and illustrate how you can interpret the trace data:

- The QS log always contains the QSPY application version number, the date and
time of the run, and all the options explicitly provided to the QSPY host
application.
- A log typically starts with the dictionary records that provide a mapping
between addresses of various objects in memory and their symbolic names. The
dictionary entries don't have timestamps.
- After the dictionaries, you see the active object initialization. For
example, the EQ.INIT record indicates event queue initialization with the
l_tableQueueSto buffer. After this the AO.ADD trace record you see adding the
Table object with priority 6. At this point, the time tick interrupt is not
configured, so all timestamps are 0000000000 (timestamps are always placed in
the first 8 columns).
- Active object initialization can contain dictionary entries for items that
are encapsulated within the active object. For example initialization of Table
inserts an object dictionary entry for @c l_table object and three function
dictionary entries for state handlers @c QHsm_top, @c Table_initial and
@c Table_serving. Finally, the top-most initial transition is taken from @c
QHsm_top to @c Table_serving.
- After the active object initialization, interrupts are enabled, and the
first Tick interrupt arrives at the timestamp 0000070346. You can find out the
type of the interrupt by the unique priority number. For example, the priority
of the Tick interrupt is 0xFF == 255.


@section QSPY_QEP QEP Trace Records

<TABLE SUMMARY="QEP Records" cellSpacing=4 cellPadding=1 border=0 width="95%">
  <TR bgColor="#c8cedc">
    <TD><B>Rec.@n Num.</B></TD>
    <TD><B>Rec.@n Enum.</B></TD>
    <TD><B>QSPY@n Abbrev.@n</B></TD>
    <TD><B>Comment</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>0</TD>
    <TD>#QS_QEP_STATE_EMPTY</TD>
    <TD></TD>
    <TD></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>1</TD>
    <TD>#QS_QEP_STATE_ENTRY</TD>
    <TD>Q_ENTRY</TD>
    <TD>a state was entered</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>2</TD>
    <TD>#QS_QEP_STATE_EXIT</TD>
    <TD>Q_EXIT</TD>
    <TD>a state was exited</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>3</TD>
    <TD>#QS_QEP_STATE_INIT</TD>
    <TD>Q_INIT</TD>
    <TD>an intial transition was taken in a state</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>4</TD>
    <TD>#QS_QEP_INIT_TRAN</TD>
    <TD>==>Init</TD>
    <TD>the top-most initial transition was taken</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>5</TD>
    <TD>#QS_QEP_INTERN_TRAN</TD>
    <TD>Intern</TD>
    <TD>an internal transition was taken</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>6</TD>
    <TD>#QS_QEP_TRAN</TD>
    <TD>==>Tran</TD>
    <TD>a regular transition was taken</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>7</TD>
    <TD>#QS_QEP_IGNORED</TD>
    <TD>Ignored</TD>
    <TD>an event was ignored (silently discarded)</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>8</TD>
    <TD>#QS_QEP_DISPATCH</TD>
    <TD>Disp==></TD>
    <TD>an event was dispatched (begin of RTC step)</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>9</TD>
    <TD>#QS_QEP_UNHANDLED</TD>
    <TD>==>UnHd</TD>
    <TD>a guard prevented handling of an event</TD>
  </TR>
</TABLE>

@section QSPY_QF QF Trace Records

<TABLE SUMMARY="QF Records" cellSpacing=4 cellPadding=1 border=0 width="95%">
  <TR bgColor="#c8cedc">
    <TD><B>Rec.@n Num.</B></TD>
    <TD><B>Rec.@n Enum.</B></TD>
    <TD><B>QSPY@n Abbrev.@n</B></TD>
    <TD><B>Comment</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>10</TD>
    <TD>#QS_QF_ACTIVE_ADD</TD>
    <TD>ADD</TD>
    <TD>an AO has been added to QF (started)</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>11</TD>
    <TD>#QS_QF_ACTIVE_REMOVE</TD>
    <TD>REM</TD>
    <TD>an AO has been removed from QF (stopped)</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>12</TD>
    <TD>#QS_QF_ACTIVE_SUBSCRIBE</TD>
    <TD>SUB</TD>
    <TD>an AO subscribed to an event</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>13</TD>
    <TD>#QS_QF_ACTIVE_UNSUBSCRIBE</TD>
    <TD>USUB</TD>
    <TD>an AO unsubscribed to an event</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>14</TD>
    <TD>#QS_QF_ACTIVE_POST_FIFO</TD>
    <TD>AO.FIFO</TD>
    <TD>an event was posted (FIFO) directly to AO</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>15</TD>
    <TD>#QS_QF_ACTIVE_POST_LIFO</TD>
    <TD>AO.LIFO</TD>
    <TD>an event was posted (LIFO) directly to AO</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>16</TD>
    <TD>#QS_QF_ACTIVE_GET</TD>
    <TD>AO.GET</TD>
    <TD>AO got an event and its queue is still not empty</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>17</TD>
    <TD>#QS_QF_ACTIVE_GET_LAST</TD>
    <TD>AO.GETL</TD>
    <TD>AO got an event and its queue is empty</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>18</TD>
    <TD>#QS_QF_EQUEUE_INIT</TD>
    <TD>EQ.INIT</TD>
    <TD>an event queue was initialized</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>19</TD>
    <TD>#QS_QF_EQUEUE_POST_FIFO</TD>
    <TD>EQ.FIFO</TD>
    <TD>an event was posted (FIFO) to a raw queue</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>20</TD>
    <TD>#QS_QF_EQUEUE_POST_LIFO</TD>
    <TD>EQ.LIFO</TD>
    <TD>an event was posted (LIFO) to a raw queue</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>21</TD>
    <TD>#QS_QF_EQUEUE_GET</TD>
    <TD>EQ.GET</TD>
    <TD>get an event and queue still not empty</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>22</TD>
    <TD>#QS_QF_EQUEUE_GET_LAST</TD>
    <TD>EQ.GETL</TD>
    <TD>get the last event from the queue</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>23</TD>
    <TD>#QS_QF_MPOOL_INIT</TD>
    <TD>MP.INIT</TD>
    <TD>a memory pool was initialized</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>24</TD>
    <TD>#QS_QF_MPOOL_GET</TD>
    <TD>MP.GET</TD>
    <TD>a memory block was removed from a memory pool</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>25</TD>
    <TD>#QS_QF_MPOOL_PUT</TD>
    <TD>MP.PUT</TD>
    <TD>a memory block was returned to a memory pool</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>26</TD>
    <TD>#QS_QF_PUBLISH</TD>
    <TD>PUBLISH</TD>
    <TD>an event was published</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>27</TD>
    <TD>#reserved</TD>
    <TD></TD>
    <TD></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>28</TD>
    <TD>#QS_QF_NEW</TD>
    <TD>NEW</TD>
    <TD>new event creation</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>29</TD>
    <TD>#QS_QF_GC_ATTEMPT</TD>
    <TD>GC-ATT</TD>
    <TD>garbage collection attempt</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>30</TD>
    <TD>#QS_QF_GC</TD>
    <TD>GC</TD>
    <TD>garbage collection performed</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>31</TD>
    <TD>#QS_QF_TICK</TD>
    <TD>TICK</TD>
    <TD>QF_tick() was called</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>32</TD>
    <TD>#QS_QF_TIMEEVT_ARM</TD>
    <TD>TE.ARM</TD>
    <TD>a time event was armed</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>33</TD>
    <TD>#QS_QF_TIMEEVT_AUTO_DISARM</TD>
    <TD>TE.ADRM</TD>
    <TD>a time event expired and was disarmed</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>34</TD>
    <TD>#QS_QF_TIMEEVT_DISARM_ATTEMPT</TD>
    <TD>TE.DATT</TD>
    <TD>attempt to disarmed a disarmed tevent</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>35</TD>
    <TD>#QS_QF_TIMEEVT_DISARM</TD>
    <TD>TE.DARM</TD>
    <TD>true disarming of an armed time event</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>36</TD>
    <TD>#QS_QF_TIMEEVT_REARM</TD>
    <TD>TE.RARM</TD>
    <TD>rearming of a time event</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>37</TD>
    <TD>#QS_QF_TIMEEVT_POST</TD>
    <TD>TE.POST</TD>
    <TD>a time event posted itself directly to an AO</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>38</TD>
    <TD>#reserved</TD>
    <TD></TD>
    <TD></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>39</TD>
    <TD>#QS_QF_INT_LOCK</TD>
    <TD>QF_intL</TD>
    <TD>interrupts were locked</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>40</TD>
    <TD>#QS_QF_INT_UNLOCK</TD>
    <TD>QF_intU</TD>
    <TD>interrupts were unlocked</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>42</TD>
    <TD>#QS_QF_ISR_ENTRY</TD>
    <TD>QF_isrE</TD>
    <TD>an ISR was entered</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>42</TD>
    <TD>#QS_QF_ISR_EXIT</TD>
    <TD>QF_isrX</TD>
    <TD>an ISR was exited</TD>
  </TR>
</TABLE>

@section QSPY_QK QK Trace Records

<TABLE SUMMARY="QK Records" cellSpacing=4 cellPadding=1 border=0 width="95%">
  <TR bgColor="#c8cedc">
    <TD><B>Rec.@n Num.</B></TD>
    <TD><B>Rec.@n Enum.</B></TD>
    <TD><B>QSPY@n Abbrev.@n</B></TD>
    <TD><B>Comment</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>50</TD>
    <TD>#QS_QK_MUTEX_LOCK</TD>
    <TD>QK_muxL</TD>
    <TD>the QK mutex was locked</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>51</TD>
    <TD>#QS_QK_MUTEX_UNLOCK</TD>
    <TD>QK_muxU</TD>
    <TD>the QK mutex was unlocked</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>52</TD>
    <TD>#QS_QK_SCHEDULE</TD>
    <TD>QK_sche</TD>
    <TD>the QK scheduled a new task to execute</TD>
  </TR>
</TABLE>

@section QSPY_MISC Miscellaneous Trace Records

<TABLE SUMMARY="Miscellaneous Records" cellSpacing=4 cellPadding=1 border=0
width="95%">
  <TR bgColor="#c8cedc">
    <TD><B>Rec.@n Num.</B></TD>
    <TD><B>Rec.@n Enum.</B></TD>
    <TD><B>QSPY@n Abbrev.@n</B></TD>
    <TD><B>Comment</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>60</TD>
    <TD>#QS_SIG_DICTIONARY</TD>
    <TD>Sig Dic</TD>
    <TD>signal dictionary entry</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>61</TD>
    <TD>#QS_OBJ_DICTIONARY</TD>
    <TD>Obj Dic</TD>
    <TD>object dictionary entry</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>62</TD>
    <TD>#QS_FUN_DICTIONARY</TD>
    <TD>Fun Dic</TD>
    <TD>function dictionary entry</TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>63</TD>
    <TD>#QS_USR_DICTIONARY</TD>
    <TD>Usr Dic</TD>
    <TD>User record dictionary entry</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>...</TD>
    <TD></TD>
    <TD></TD>
    <TD></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>69</TD>
    <TD>#QS_ASSERT</TD>
    <TD>!ASSERT</TD>
    <TD>Assertion fired</TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>70</TD>
    <TD>#QS_USER</TD>
    <TD>UserXXX</TD>
    <TD>the first record available for user QS records</TD>
  </TR>
</TABLE>


@image html logo_ql_TM.jpg
Copyright &copy; 2002-2008 Quantum Leaps, LLC. All Rights Reserved.@n
http://www.state-machine.com
*/

/**
@page qspy_matlab QSPY MATLAB/GNU Octave Inteface

The QSPY host application can also export trace data to MATLAB&reg;, which is
a popular numerical computing environment and a high-level technical
programming language. Created by The MathWorks, Inc., MATLAB allows easy
manipulation and plotting of data represented as matrices.

The QSPY MATLAB interface is also compatible with the GNU Octave environment,
which is an open source alternative to MATLAB and is compatible with the
QSPY MATLAB interface described below.

The following sections provide a reference manual for all 11 the MATLAB
matrices generated by the @c qspy.m script. By MATLAB convention, the
different variables are put into columns, allowing observations to vary down
through the rows. Therefore, a data set consisting of twenty four time samples
of six variables is stored in a matrix of size 24-by-6. The pound sign '#' in
a given cell of the matrix represents data available from the target. Other
values, represent data added by the @c qspy.m script to allow unambiguous
identification of the trace records.

- @ref MATLAB_Q_STATE
- @ref MATLAB_Q_ACTIVE
- @ref MATLAB_Q_EQUEUE
- @ref MATLAB_Q_MPOOL
- @ref MATLAB_Q_NEW
- @ref MATLAB_Q_PUB
- @ref MATLAB_Q_TIME
- @ref MATLAB_Q_INT
- @ref MATLAB_Q_ISR
- @ref MATLAB_Q_MUTEX
- @ref MATLAB_Q_SCHED


@section MATLAB_Q_STATE Q_STATE Matrix

The N-by-6 @c Q_STATE matrix stores all QS records generated by the QEP
hierarchical event processor and pertaining to all the state machines in the
system. The following table summarizes how the QS records are stored in the
matrix:

<TABLE SUMMARY="Q_STATE Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
    <TD><B>4</B></TD>
    <TD><B>5</B></TD>
    <TD><B>6</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>Signal</B></TD>
    <TD><B>State@n Machine@n Object</B></TD>
    <TD><B>Source@n State</B></TD>
    <TD><B>New@n State</B></TD> <TD><B>Event@n Hanlder</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QEP_STATE_ENTRY</TD>
    <TD>NaN</TD>
    <TD>1</TD>
    <TD>#(2)</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QEP_STATE_EXIT</TD>
    <TD>NaN</TD>
    <TD>2</TD>
    <TD>#(2)</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QEP_STATE_INIT</TD>
    <TD>NaN</TD>
    <TD>3</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QEP_INIT_TRAN</TD>
    <TD>#</TD>
    <TD>3</TD>
    <TD>#(2)</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QEP_INTERN_TRAN</TD>
    <TD>#</TD>
    <TD>#(1)</TD>
    <TD>#(2)</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QEP_TRAN</TD>
    <TD>#</TD>
    <TD>#(1)</TD>
    <TD>#(2)</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QEP_IGNORED</TD>
    <TD>#</TD>
    <TD>#(1)</TD>
    <TD>#(2)</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>0</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QEP_DISPATCH</TD>
    <TD>#</TD>
    <TD>#(1)</TD>
    <TD>#(2)</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>0</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QEP_UNHANDLED</TD>
    <TD>NaN</TD>
    <TD>#(1)</TD>
    <TD>#(2)</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>0</TD>
  </TR>
</TABLE>
(1) The valid USER signal is &gt; 3

(2) Per inheritance, an active object is a state machine object as well



The following criteria (index matrices in MATLAB) unambiguously select the QS
records from the @c Q_STATE matrix:

<TABLE SUMMARY="Q_STATE records" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>QS Record</B></TD>
    <TD><B>MATLAB Index Matrix</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QEP_STATE_ENTRY</TD>
    <TD><TT>Q_STATE(:,2) == 1</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QEP_STATE_EXIT</TD>
    <TD><TT>Q_STATE(:,2) == 2</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QEP_STATE_INIT</TD>
    <TD><TT>Q_STATE(:,2) == 3</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QEP_INIT_TRAN</TD>
    <TD><TT>isnan(Q_STATE(:,4))</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QEP_INTERN_TRAN</TD>
    <TD><TT>Q_STATE(:,2) &gt; 3 & isnan(Q_STATE(:,5))</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QEP_TRAN</TD>
    <TD><TT>Q_STATE(:,2) > &gt; & ~isnan(Q_STATE(:,5))</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QEP_IGNORED</TD>
    <TD><TT>~Q_STATE(:,6)</TT></TD>
  </TR>

</TABLE>

For example, the following MATLAB plot shows the timing diagrams for all
Philo state machines in the DPP example application made by the
@c philo_timing.m script located in the directory @c @@tools@@qspy@@matlab@@
(see Section @ref files_page). The vertical axis represents states "thinking"
(lowest), "hungry" (middle) and "eating" (top) states.

@image html FigQSPY.01.jpg "Timing diagrams for all Philo state machines."

@section MATLAB_Q_ACTIVE Q_ACTIVE Matrix

The N-by-5 @c Q_ACTIVE matrix stores QS records pertaining to adding/removing
active objects and subscribing/unsubscribing to events from active objects.
The following table summarizes how the QS records are stored in the matrix:

<TABLE SUMMARY="Q_ACTIVE Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
    <TD><B>4</B></TD>
    <TD><B>5</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>Signal</B></TD>
    <TD><B>Active@n Object</B></TD>
    <TD><B>QF@n Priority</B></TD>
    <TD><B>Delta</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_ACTIVE_ADD</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_ACTIVE_REMOVE</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>-1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_ACTIVE_SUBSCRIBE</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_ACTIVE_UNSUBSCRIBE</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>-1</TD>
  </TR>
</TABLE>

The following criteria (index matrices in MATLAB) unambiguously select the QS
records from the @c Q_ACTIVE matrix:

<TABLE SUMMARY="Q_ACTIVE records" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>QS Record</B></TD>
    <TD><B>MATLAB Index Matrix</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_ACTIVE_ADD</TD>
    <TD><TT>isnan(Q_ACTIVE(:,2)) & Q_ACTIVE(:,5) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_ACTIVE_REMOVE</TD>
    <TD><TT>isnan(Q_ACTIVE(:,2)) & Q_ACTIVE(:,5) &lt; 0</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_ACTIVE_SUBSCRIBE</TD>
    <TD><TT>isnan(Q_ACTIVE(:,4)) & Q_ACTIVE(:,5) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_ACTIVE_UNSUBSCRIBE</TD>
    <TD><TT>isnan(Q_ACTIVE(:,4)) & Q_ACTIVE(:,5) &lt; 0</TT></TD>
  </TR>
</TABLE>


@section MATLAB_Q_EQUEUE Q_EQUEUE Matrix

The N-by-10 @c Q_EQUEUE matrix stores QS records pertaining to queuing events
in the QF. Both the active object event queues and the "raw" thread-safe
queues are included. The 'nUsed' field denotes the current number of used
entries in the queue. The 'Maximum nUsed' filed denotes the maximum number of
used entries since initialization (high watermark). Both fields contain the
number of used entries in the queues ring-buffer plus one, to account for the
extra location at the front of the queue. The following table summarizes how
the QS records are stored in the matrix:

<TABLE SUMMARY="Q_EQUEUE Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
    <TD><B>4</B></TD>
    <TD><B>5</B></TD>
    <TD><B>6</B></TD>
    <TD><B>7</B></TD>
    <TD><B>8</B></TD>
    <TD><B>9</B></TD>
    <TD><B>10</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>Sender</B></TD>
    <TD><B>Event@n Queue (1)</B></TD>
    <TD><B>nFree</B></TD>
    <TD><B>Minimum@n Used</B></TD>
    <TD><B>Signal</B></TD>
    <TD><B>Pool ID</B></TD>
    <TD><B>Ref.@n Count</B></TD>
    <TD><B>LIFO</B></TD>
    <TD><B>Delta</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_EQUEUE_INIT</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>0</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>0</TD>
    <TD>0</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_ACTIVE_POST_FIFO</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>0</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_ACTIVE_POST_LIFO</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>1</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_ACTIVE_GET</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>0</TD>
    <TD>-1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_ACTIVE_GET_LAST</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>0</TD>
    <TD>-1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_EQUEUE_POST_FIFO</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>1</TD>
    <TD>#</TD>
    <TD>0</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_EQUEUE_POST_LIFO</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>1</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_EQUEUE_GET</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>0</TD>
    <TD>-1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_EQUEUE_GET_LAST</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>0</TD>
    <TD>-1</TD>
  </TR>
</TABLE>
(1) This field (index 3) is actually the pointer to the ring buffer of the
queue.

The following criteria (index matrices in MATLAB) unambiguously select the QS
records from the @c Q_EQUEUE matrix:

<TABLE SUMMARY="Q_EQUEUE records" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>QS Record</B></TD>
    <TD><B>MATLAB Index Matrix</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_EQUEUE_INIT</TD>
    <TD><TT>Q_EQUEUE(:,10) == 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_ACTIVE_POST_FIFO</TD>
    <TD><TT>Q_EQUEUE(:,3) == &lt;active obj&gt; & ~Q_EQUEUE(:,9) & Q_EQUEUE(:,10) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_ACTIVE_POST_LIFO</TD>
    <TD><TT>Q_EQUEUE(:,3) == &lt;active obj&gt; & Q_EQUEUE(:,9) & Q_EQUEUE(:,10) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_ACTIVE_GET</TD>
    <TD><TT>Q_EQUEUE(:,3) == &lt;active obj&gt; & ~isnan(Q_EQUEUE(:,4) & Q_EQUEUE(:,10) &lt; 0</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_ACTIVE_GET_LAST</TD>
    <TD><TT>Q_EQUEUE(:,3) == &lt;active obj&gt; & isnan(Q_EQUEUE(:,4) & Q_EQUEUE(:,10) &lt; 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_EQUEUE_POST_FIFO</TD>
    <TD><TT>Q_EQUEUE(:,3) == &lt;raw queue&gt; & ~Q_EQUEUE(:,9) & Q_EQUEUE(:,10) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_EQUEUE_POST_LIFO</TD>
    <TD><TT>Q_EQUEUE(:,3) == &lt;raw queue&gt; & Q_EQUEUE(:,9) & Q_EQUEUE(:,10) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_EQUEUE_GET</TD>
    <TD><TT>Q_EQUEUE(:,3) == &lt;raw queue&gt; & ~isnan(Q_EQUEUE(:,4) & Q_EQUEUE(:,10) &lt; 0</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_EQUEUE_GET_LAST</TD>
    <TD><TT>Q_EQUEUE(:,3) == &lt;raw queue&gt; & isnan(Q_EQUEUE(:,4) & Q_EQUEUE(:,10) &lt; 0</TT></TD>
  </TR>
</TABLE>


@section MATLAB_Q_MPOOL Q_MPOOL Matrix

The N-by-5 @c Q_MPOOL matrix stores QS records pertaining to memory pools in
the QF. The 'nFree' field denotes the current number of free blocks in the
event pool. The 'Minimum nFree' filed denotes the minimal number of free
blocks since initialization (low watermark). The following table summarizes
how the QS records are stored in the matrix:

<TABLE SUMMARY="Q_MPOOL Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
    <TD><B>4</B></TD>
    <TD><B>5</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>Pool@n Object</B></TD>
    <TD><B>nFree</B></TD>
    <TD><B>Minimal@n nFree</B></TD>
    <TD><B>Delta</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_MPOOL_INIT</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>0</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_MPOOL_GET</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>-1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_MPOOL_PUT</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>+1</TD>
  </TR>
</TABLE>

The cumulative sum over the 'Delta' column should not have any long-time
trends, because this would indicate a leak from the pool. The following
picture shows the plot for the test data.

@image html FigQSPY.02.jpg "Plot stairs(Q_MPOOL(:,1), cumsum(Q_MPOOL(:,5)))"

The following criteria (index matrices in MATLAB) unambiguously select the QS
records from the @c Q_MPOOL matrix:

<TABLE SUMMARY="Q_MPOOL records" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>QS Record</B></TD>
    <TD><B>MATLAB Index Matrix</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_MPOOL_INIT</TD>
    <TD><TT>Q_MPOOL(:,5) == 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_MPOOL_GET</TD>
    <TD><TT>Q_MPOOL(:,5) &lt; 0</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_MPOOL_PUT</TD>
    <TD><TT>Q_MPOOL(:,5) &gt; 0</TT></TD>
  </TR>
</TABLE>


@section MATLAB_Q_NEW Q_NEW Matrix

The N-by-6 @c Q_NEW matrix stores QS records pertaining to dynamic event
allocation and automatic event recycling (garbage collection) in the QF. The
following table summarizes how the QS records are stored in the matrix:

<TABLE SUMMARY="Q_NEW Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
    <TD><B>4</B></TD>
    <TD><B>5</B></TD>
    <TD><B>6</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>Signal</B></TD>
    <TD><B>PoolID</B></TD>
    <TD><B>Ref.@n Count</B></TD>
    <TD><B>Event@n Size</B></TD>
    <TD><B>Delta</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_NEW</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_GC_ATTEMPT</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>0</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_GC</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>-1</TD>
  </TR>
</TABLE>

The cumulative sum over the 'Delta' column should not have any long-time
trends, because this would indicate event leak. The following picture shows
the plot for the test data.

@image html FigQSPY.03.jpg "Plot stairs(Q_NEW(:,1), cumsum(Q_NEW(:,6)))"

The following criteria (index matrices in MATLAB) unambiguously select the QS
records from the @c Q_NEW matrix:

<TABLE SUMMARY="Q_NEW records" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>QS Record</B></TD>
    <TD><B>MATLAB Index Matrix</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_NEW</TD>
    <TD><TT>%Q_NEW(:,6) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_GC_ATTEMPT</TD>
    <TD><TT>%Q_NEW(:,6) == 0</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_GC</TD>
    <TD><TT>%Q_NEW(:,6) &lt; 0</TT></TD>
  </TR>
</TABLE>


@section MATLAB_Q_PUB Q_PUB Matrix

The N-by-7 @c Q_PUB matrix stores QS records pertaining to publishing events
in QF. The following table summarizes how the QS records are stored in the
matrix:

<TABLE SUMMARY="Q_PUB Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
    <TD><B>4</B></TD>
    <TD><B>5</B></TD>
    <TD><B>6</B></TD>
    <TD><B>7</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>Sender</B></TD>
    <TD><B>Signal</B></TD>
    <TD><B>PoolID</B></TD>
    <TD><B>Ref.@n Count</B></TD>
    <TD><B># Events@n Multicast</B></TD>
    <TD><B>Delta</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_PUBLISH</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
  </TR>
</TABLE>

The following criteria (index matrices in MATLAB) unambiguously select the QS
records from the @c Q_PUB matrix:

<TABLE SUMMARY="Q_PUB records" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>QS Record</B></TD>
    <TD><B>MATLAB Index Matrix</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_PUBLISH</TD>
    <TD><TT>Q_PUB(:,7) &gt; 0</TT></TD>
  </TR>
</TABLE>


@section MATLAB_Q_TIME Q_TIME Matrix

The N-by-7 @c Q_TIME matrix stores QS records pertaining to time events in QF.
The following table summarizes how the QS records are stored in the matrix:

<TABLE SUMMARY="Q_TIME Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
    <TD><B>4</B></TD>
    <TD><B>5</B></TD>
    <TD><B>6</B></TD>
    <TD><B>7</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>QTimeEvt@n Object</B></TD>
    <TD><B>Signal</B></TD>
    <TD><B>QActive@n Object</B></TD>
    <TD><B>QTimeEvt@n Counter</B></TD>
    <TD><B>QTimeEvt@n Interval</B></TD>
    <TD><B>QTimeEvt@n Delta</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_TICK</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>#(1)</TD>
    <TD>NaN</TD>
    <TD>0</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_TIMEEVT_ARM</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_TIMEEVT_DISARM</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>-1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_TIMEEVT_AUTO_DISARM</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>-1</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_TIMEEVT_DISARM_ATTEMPT</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>0</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_TIMEEVT_REARM</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#(2)</TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_TIMEEVT_POST</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>NaN</TD>
    <TD>NaN</TD>
    <TD>0</TD>
  </TR>
</TABLE>
(1) For #QS_QF_TICK record this matrix element contains the Tick Counter.

(2) For #QS_QF_TIMEEVT_REARM event this matrix element is 0 if the time
event was disarmed and rearmed again, and 1 if the time event was only armed.

The cumulative sum over the 'Delta' column indicates the total number of armed
time events at any given time. The following picture shows the plot for the
test data:

@image html FigQSPY.04.jpg "Plot stairs(Q_TIME(:,1), cumsum(Q_TIME(:,7)))"

The following criteria (index matrices in MATLAB) unambiguously select the QS
records from the @c Q_TIME matrix:

<TABLE SUMMARY="Q_TIME records" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>QS Record</B></TD>
    <TD><B>MATLAB Index Matrix</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_TICK</TD>
    <TD><TT>isnan(Q_TIME(:,2))</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_TIMEEVT_ARM</TD>
    <TD><TT>Q_TIME(:,7) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_TIMEEVT_DISARM</TD>
    <TD><TT>~isnan(Q_TIME(:,1)) & Q_TIME(:,7) &lt; 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_TIMEEVT_AUTO_DISARM</TD>
    <TD><TT>isnan(Q_TIME(:,1)) & Q_TIME(:,7) &lt; 0</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_TIMEEVT_DISARM_ATTEMPT</TD>
    <TD><TT>isnan(Q_TIME(:,3)) & isnan(Q_TIME(:,5)) & Q_TIME(:,7) == 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_TIMEEVT_REARM</TD>
    <TD><TT>isnan(Q_TIME(:,3)) & ~isnan(Q_TIME(:,5))</TT></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_TIMEEVT_POST</TD>
    <TD><TT>~isnan(Q_TIME(:,3)) & ~isnan(Q_TIME(:,4))</TT></TD>
  </TR>
</TABLE>


@section MATLAB_Q_INT Q_INT Matrix

The N-by-3 @c Q_INT matrix stores QS records pertaining to interrupt locking
and unlocking. The following table summarizes how the QS records are stored in
the matrix:

<TABLE SUMMARY="Q_INT Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>Interrupt@n Nesting</B></TD>
    <TD><B>Nesting@n Delta</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_INT_LOCK</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_INT_UNLOCK</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>-1</TD>
  </TR>
</TABLE>

The cumulative sum over the 'Delta' column indicates interrupt lock nesting
and should closely follow column 2.

The following criteria (index matrices in MATLAB) unambiguously select the QS
records from the @c Q_INT matrix:

<TABLE SUMMARY="Q_INT records" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>QS Record</B></TD>
    <TD><B>MATLAB Index Matrix</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_INT_LOCK</TD>
    <TD><TT>Q_INT(:,3) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_INT_UNLOCK</TD>
    <TD><TT>Q_INT(:,3) &lt; 0</TT></TD>
  </TR>
</TABLE>


@section MATLAB_Q_ISR Q_ISR Matrix

The N-by-4 @c Q_ISR matrix stores QS records pertaining to interrupt entry and
exit. The following table summarizes how the QS records are stored in the
matrix:

<TABLE SUMMARY="Q_ISR Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
    <TD><B>4</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>Interrupt@n Nesting</B></TD>
    <TD><B>ISR@n Priority</B></TD>
    <TD><B>Nesting@n Delta</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QF_ISR_ENTRY</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QF_ISR_EXIT</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>-1</TD>
  </TR>
</TABLE>

The cumulative sum over the 'Delta' column indicates interrupt nesting level
and should closely follow column 2.

The following criteria (index matrices in MATLAB) unambiguously select the QS
records from the @c Q_ISR matrix:

<TABLE SUMMARY="Q_ISR records" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>QS Record</B></TD>
    <TD><B>MATLAB Index Matrix</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QF_ISR_ENTRY</TD>
    <TD><TT>Q_ISR(:,4) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QF_ISR_EXIT</TD>
    <TD><TT>Q_ISR(:,4) &lt; 0</TT></TD>
  </TR>
</TABLE>


@section MATLAB_Q_MUTEX Q_MUTEX Matrix

The N-by-4 @c Q_MUTEX matrix stores QS records pertaining to the
priority-ceiling mutex activity in QK. The following table summarizes how the
QS records are stored in the matrix:

<TABLE SUMMARY="Q_MUTEX Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
    <TD><B>4</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>Original@n Priority</B></TD>
    <TD><B>Priority@n Ceiling</B></TD>
    <TD><B>Nesting@n Delta</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QK_MUTEX_LOCK</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>+1</TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD>@c #QS_QK_MUTEX_UNLOCK</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>-1</TD>
  </TR>
</TABLE>


The cumulative sum over the 'Delta' column indicates QK scheduler lock nesting
level.

@image html FigQSPY.05.jpg "Plot stairs(Q_MUTEX(:,1), cumsum(Q_MUTEX(:,4)), 'r') (red)"


The following criteria (index matrices in MATLAB) unambiguously select the QS
records from the @c Q_ISR matrix:

<TABLE SUMMARY="Q_ISR records" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>QS Record</B></TD>
    <TD><B>MATLAB Index Matrix</B></TD>
  </TR>

  <TR bgColor="#f0f0f0">
    <TD>@c #QS_QK_MUTEX_LOCK</TD>
    <TD><TT>Q_MUTEX(:,4) &gt; 0</TT></TD>
  </TR>

  <TR bgColor="#c0c0c0">
    <TD>@c #QS_QK_MUTEX_UNLOCK</TD>
    <TD><TT>Q_MUTEX(:,4) &lt; 0</TT></TD>
  </TR>
</TABLE>


@section MATLAB_Q_SCHED Q_SCHED Matrix

The N-by-3 @c Q_SCHED matrix stores QS records pertaining to scheduling next
task in QK. The following table summarizes how the QS records are stored in
the matrix:

<TABLE SUMMARY="Q_MUTEX Matrix" cellSpacing=4 cellPadding=1 border=0
ALIGN="center">
  <TR bgColor="#c8cedc" ALIGN="center">
    <TD><B>&nbsp;MATLAB index --&gt;</B></TD>
    <TD><B>1</B></TD>
    <TD><B>2</B></TD>
    <TD><B>3</B></TD>
  </TR>

  <TR bgColor="#f0f0f0" ALIGN="center">
    <TD><B>QS Record@n |@n V</B></TD>
    <TD><B>Time@n Stamp</B></TD>
    <TD><B>Preempted@n Priority</B></TD>
    <TD><B>New@n Priority</B></TD>
  </TR>

  <TR bgColor="#c0c0c0" ALIGN="center">
    <TD>@c #QS_QK_SCHEDULE</TD>
    <TD>#</TD>
    <TD>#</TD>
    <TD>#</TD>
  </TR>
</TABLE>


<HR>

@image html logo_ql_TM.jpg
Copyright &copy; 2002-2011 Quantum Leaps, LLC. All Rights Reserved.@n
http://www.state-machine.com
*/

/**
@page qspy_mscgen QSPY MscGen Inteface

The QSPY host application can also generate data for the MscGen utility
(http://www.mcternan.me.uk/mscgen/) to generate <b>sequence diagrams</b>.

@note The MscGen utility is also available in the <b>Qtools</b> collection
(http://www.state-machine.com/downloads/index.php#QTOOLS).

To generate an MscGen file, you need to invoke QSPY with  the
-g&lt;msc-file&gt; option:

@verbatim
qspy -gdpp.msc ...
@endverbatim

where &lt;msc-file&gt; is the file name to gnerate.

@note The generation of sequence diagrams relies on the following
QS trace records being enabled: @c QS_QF_ACTIVE_POST_FIFO,
@c QS_QF_ACTIVE_POST_LIFO. Additional annotations of the sequence
diagrams are also available if the following QS trace records
are enabled: @c QS_QF_PUBLISH, @c QS_QF_TICK, and @c QS_QEP_TRAN. 

Subsequently, you need to invoke the MscGen utility to convert
the generated file to graphical format, such as .PNG, .EPS, .SVG, or .ISMAP.
For example, the following command generates a sequence diagram in .SVG from
the dpp.msc file.

@verbatim
mscgen -Tsvg -idpp.msc
@endverbatim

The following screen shot shows a sequence diagram generated from the
Dining Philosophers Problem (DPP) application. The .MSC file has been
converted to .SVG and viewed in a web browser (Google Chrome in this case).

@image html mscgen_dpp.png


@note The numbers preceeding the signal names in the diagram are the time
stamps.


<HR>

@image html logo_ql_TM.jpg
Copyright &copy; 2002-2011 Quantum Leaps, LLC. All Rights Reserved.@n
http://www.state-machine.com
*/
