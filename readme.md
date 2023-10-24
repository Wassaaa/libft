<a name="br1"></a> 

Libft

Your very ﬁrst own library

Summary:

This project is about coding a C library.

It will contain a lot of general purpose functions your programs will rely upon.

Version: 15



<a name="br2"></a> 

Contents

[I](#br3)

[Introduction](#br3)

2

3

[II](#br4)

[III](#br6)

[Common](#br4)[ ](#br4)[Instructions](#br4)

[Mandatory](#br6)[ ](#br6)[part](#br6)

5

5

6

7

[III.1](#br6)

[III.2](#br7)

[III.3](#br8)

[Technical](#br6)[ ](#br6)[considerations](#br6)[ ](#br6). . . . . . . . . . . . . . . . . . . . . . . . . .

[Part](#br7)[ ](#br7)[1](#br7)[ ](#br7)[-](#br7)[ ](#br7)[Libc](#br7)[ ](#br7)[functions](#br7)[ ](#br7). . . . . . . . . . . . . . . . . . . . . . . . . .

[Part](#br8)[ ](#br8)[2](#br8)[ ](#br8)[-](#br8)[ ](#br8)[Additional](#br8)[ ](#br8)[functions](#br8)[ ](#br8). . . . . . . . . . . . . . . . . . . . . . .

[IV](#br12)

[V](#br16)

[Bonus](#br12)[ ](#br12)[part](#br12)

11

15

[Submission](#br16)[ ](#br16)[and](#br16)[ ](#br16)[peer-evaluation](#br16)

1



<a name="br3"></a> 

Chapter I

Introduction

C programming can be very tedious when one doesn’t have access to the highly useful

standard functions. This project is about understanding the way these functions work,

implementing and learning to use them. Your will create your own library. It will be

helpful since you will use it in your next C school assignments.

Take the time to expand your libft throughout the year. However, when working

on a new project, don’t forget to ensure the functions used in your library are allowed in

the project guidelines.

2



<a name="br4"></a> 

Chapter II

Common Instructions

• Your project must be written in C.

• Your project must be written in accordance with the Norm. If you have bonus

ﬁles/functions, they are included in the norm check and you will receive a 0 if there

is a norm error inside.

• Your functions should not quit unexpectedly (segmentation fault, bus error, double

free, etc) apart from undeﬁned behaviors. If this happens, your project will be

considered non functional and will receive a 0 during the evaluation.

• All heap allocated memory space must be properly freed when necessary. No leaks

will be tolerated.

• If the subject requires it, you must submit a Makefile which will compile your

source ﬁles to the required output with the ﬂags -Wall, -Wextra and -Werror, use

cc, and your Makeﬁle must not relink.

• Your Makefile must at least contain the rules $(NAME), all, clean, fclean and

re.

• To turn in bonuses to your project, you must include a rule bonus to your Makeﬁle,

which will add all the various headers, librairies or functions that are forbidden on

the main part of the project. Bonuses must be in a diﬀerent ﬁle \_bonus.{c/h} if

the subject does not specify anything else. Mandatory and bonus part evaluation

is done separately.

• If your project allows you to use your libft, you must copy its sources and its

associated Makefile in a libft folder with its associated Makeﬁle. Your project’s

Makefile must compile the library by using its Makefile, then compile the project.

• We encourage you to create test programs for your project even though this work

won’t have to be submitted and won’t be graded. It will give you a chance

to easily test your work and your peers’ work. You will ﬁnd those tests especially

useful during your defence. Indeed, during defence, you are free to use your tests

and/or the tests of the peer you are evaluating.

• Submit your work to your assigned git repository. Only the work in the git reposi-

tory will be graded. If Deepthought is assigned to grade your work, it will be done

3



<a name="br5"></a> 

Libft

Your very ﬁrst own library

after your peer-evaluations. If an error happens in any section of your work during

Deepthought’s grading, the evaluation will stop.

4



<a name="br6"></a> 

Chapter III

Mandatory part

Program name

Turn in ﬁles

Makeﬁle

External functs.

Libft authorized

~~Description~~

libft.a

Makefile, libft.h, ft\_\*.c

NAME, all, clean, fclean, re

Detailed below

n/a

Write your own library: a collection of functions

that will be a useful tool for your cursus.

III.1 Technical considerations

• Declaring global variables is forbidden.

• If you need helper functions to split a more complex function, deﬁne them as static

functions. This way, their scope will be limited to the appropriate ﬁle.

• Place all your ﬁles at the root of your repository.

• Turning in unused ﬁles is forbidden.

• Every .c ﬁles must compile with the ﬂags -Wall -Wextra -Werror.

• You must use the command ar to create your library. Using the libtool command

is forbidden.

• Your libft.a has to be created at the root of your repository.

5



<a name="br7"></a> 

Libft

Your very ﬁrst own library

III.2 Part 1 - Libc functions

To begin, you must redo a set of functions from the libc. Your functions will have the

same prototypes and implement the same behaviors as the originals. They must comply

with the way they are deﬁned in their man. The only diﬀerence will be their names. They

will begin with the ’ft\_’ preﬁx. For instance, strlen becomes ft\_strlen.

Some of the functions’ prototypes you have to redo use the ’restrict’

qualifier. This keyword is part of the c99 standard. It is

therefore forbidden to include it in your own prototypes and to

compile your code with the -std=c99 flag.

You must write your own function implementing the following original ones. They do

not require any external functions:

• isalpha

• isdigit

• isalnum

• isascii

• isprint

• strlen

• memset

• bzero

• memcpy

• memmove

• strlcpy

• strlcat

• toupper

• tolower

• strchr

•

strrchr

• strncmp

• memchr

• memcmp

• strnstr

• atoi

In order to implement the two following functions, you will use malloc():

• calloc

• strdup

6



<a name="br8"></a> 

Libft

Your very ﬁrst own library

III.3 Part 2 - Additional functions

In this second part, you must develop a set of functions that are either not in the libc,

or that are part of it but in a diﬀerent form.

Some of the following functions can be useful for writing the

functions of Part 1.

Function name

~~Prototype~~

ft\_substr

char \*ft\_substr(char const \*s, unsigned int start,

size\_t len);

Turn in ﬁles

~~Parameters~~

\-

s: The string from which to create the substring.

start: The start index of the substring in the

string ’s’.

len: The maximum length of the substring.

The substring.

Return value

NULL if the allocation fails.

malloc

Allocates (with malloc(3)) and returns a substring

from the string ’s’.

External functs.

~~Description~~

The substring begins at index ’start’ and is of

maximum size ’len’.

Function name

~~Prototype~~

ft\_strjoin

char \*ft\_strjoin(char const \*s1, char const \*s2);

\-

Turn in ﬁles

Parameters

s1: The prefix string.

s2: The suffix string.

Return value

The new string.

NULL if the allocation fails.

malloc

Allocates (with malloc(3)) and returns a new

string, which is the result of the concatenation

of ’s1’ and ’s2’.

External functs.

~~Description~~

7



<a name="br9"></a> 

Libft

Your very ﬁrst own library

Function name

~~Prototype~~

ft\_strtrim

char \*ft\_strtrim(char const \*s1, char const \*set);

\-

Turn in ﬁles

Parameters

s1: The string to be trimmed.

set: The reference set of characters to trim.

The trimmed string.

NULL if the allocation fails.

malloc

Allocates (with malloc(3)) and returns a copy of

’s1’ with the characters specified in ’set’ removed

from the beginning and the end of the string.

Return value

External functs.

~~Description~~

Function name

Prototype

ft\_split

char \*\*ft\_split(char const \*s, char c);

\-

Turn in ﬁles

Parameters

s: The string to be split.

c: The delimiter character.

The array of new strings resulting from the split.

NULL if the allocation fails.

malloc, free

Allocates (with malloc(3)) and returns an array

of strings obtained by splitting ’s’ using the

character ’c’ as a delimiter. The array must end

with a NULL pointer.

~~Return value~~

External functs.

~~Description~~

Function name

Prototype

Turn in ﬁles

Parameters

Return value

ft\_itoa

char \*ft\_itoa(int n);

\-

n: the integer to convert.

The string representing the integer.

NULL if the allocation fails.

malloc

External functs.

~~Description~~

Allocates (with malloc(3)) and returns a string

representing the integer received as an argument.

Negative numbers must be handled.

8



<a name="br10"></a> 

Libft

Your very ﬁrst own library

Function name

~~Prototype~~

ft\_strmapi

char \*ft\_strmapi(char const \*s, char (\*f)(unsigned

int, char));

Turn in ﬁles

Parameters

\-

s: The string on which to iterate.

f: The function to apply to each character.

The string created from the successive applications

of ’f’.

~~Return value~~

Returns NULL if the allocation fails.

malloc

Applies the function ’f’ to each character of the

string ’s’, and passing its index as first argument

to create a new string (with malloc(3)) resulting

from successive applications of ’f’.

External functs.

~~Description~~

Function name

~~Prototype~~

ft\_striteri

void ft\_striteri(char \*s, void (\*f)(unsigned int,

char\*));

Turn in ﬁles

Parameters

\-

s: The string on which to iterate.

f: The function to apply to each character.

None

Return value

External functs.

~~Description~~

None

Applies the function ’f’ on each character of

the string passed as argument, passing its index

as first argument. Each character is passed by

address to ’f’ to be modified if necessary.

Function name

Prototype

ft\_putchar\_fd

void ft\_putchar\_fd(char c, int fd);

Turn in ﬁles

Parameters

\-

c: The character to output.

fd: The file descriptor on which to write.

None

write

Return value

External functs.

~~Description~~

Outputs the character ’c’ to the given file

descriptor.

9



<a name="br11"></a> 

Libft

Your very ﬁrst own library

Function name

Prototype

ft\_putstr\_fd

void ft\_putstr\_fd(char \*s, int fd);

Turn in ﬁles

Parameters

\-

s: The string to output.

fd: The file descriptor on which to write.

None

write

Return value

External functs.

Description

Outputs the string ’s’ to the given file

descriptor.

Function name

Prototype

ft\_putendl\_fd

void ft\_putendl\_fd(char \*s, int fd);

Turn in ﬁles

Parameters

\-

s: The string to output.

fd: The file descriptor on which to write.

None

write

Return value

External functs.

~~Description~~

Outputs the string ’s’ to the given file descriptor

followed by a newline.

Function name

Prototype

ft\_putnbr\_fd

void ft\_putnbr\_fd(int n, int fd);

Turn in ﬁles

Parameters

\-

n: The integer to output.

fd: The file descriptor on which to write.

None

write

Return value

External functs.

Description

Outputs the integer ’n’ to the given file

descriptor.

10



<a name="br12"></a> 

Chapter IV

Bonus part

If you completed the mandatory part, do not hesitate to go further by doing this extra

one. It will bring bonus points if passed successfully.

Functions to manipulate memory and strings is very useful. But you will soon discover

that manipulating lists is even more useful.

You have to use the following structure to represent a node of your list. Add its

declaration to your libft.h ﬁle:

typedef struct

s\_list

{

void

\*content;

\*next;

t\_list;

struct s\_list

}

The members of the t\_list struct are:

• content: The data contained in the node.

void \* allows to store any kind of data.

• next: The address of the next node, or NULL if the next node is the last one.

In your Makeﬁle, add a make bonus rule to add the bonus functions to your libft.a.

The bonus part will only be assessed if the mandatory part is

PERFECT. Perfect means the mandatory part has been integrally done

and works without malfunctioning. If you have not passed ALL the

mandatory requirements, your bonus part will not be evaluated at all.

11



<a name="br13"></a> 

Libft

Your very ﬁrst own library

Implement the following functions in order to easily use your lists.

Function name

Prototype

ft\_lstnew

t\_list \*ft\_lstnew(void \*content);

\-

content: The content to create the node with.

The new node

malloc

Allocates (with malloc(3)) and returns a new node.

The member variable ’content’ is initialized with

the value of the parameter ’content’. The variable

’next’ is initialized to NULL.

Turn in ﬁles

~~Parameters~~

Return value

External functs.

~~Description~~

Function name

~~Prototype~~

ft\_lstadd\_front

void ft\_lstadd\_front(t\_list \*\*lst, t\_list \*new);

Turn in ﬁles

~~Parameters~~

\-

lst: The address of a pointer to the first link of

a list.

new: The address of a pointer to the node to be

added to the list.

None

None

Return value

External functs.

~~Description~~

Adds the node ’new’ at the beginning of the list.

Function name

Prototype

ft\_lstsize

int ft\_lstsize(t\_list \*lst);

Turn in ﬁles

Parameters

\-

lst: The beginning of the list.

The length of the list

None

Return value

External functs.

Description

Counts the number of nodes in a list.

Function name

Prototype

ft\_lstlast

t\_list \*ft\_lstlast(t\_list \*lst);

Turn in ﬁles

Parameters

\-

lst: The beginning of the list.

Last node of the list

None

Return value

External functs.

Description

Returns the last node of the list.

12



<a name="br14"></a> 

Libft

Your very ﬁrst own library

Function name

~~Prototype~~

ft\_lstadd\_back

void ft\_lstadd\_back(t\_list \*\*lst, t\_list \*new);

Turn in ﬁles

~~Parameters~~

\-

lst: The address of a pointer to the first link of

a list.

new: The address of a pointer to the node to be

added to the list.

None

None

Return value

External functs.

~~Description~~

Adds the node ’new’ at the end of the list.

Function name

~~Prototype~~

ft\_lstdelone

void ft\_lstdelone(t\_list \*lst, void (\*del)(void

\*));

Turn in ﬁles

Parameters

\-

lst: The node to free.

del: The address of the function used to delete

the content.

Return value

External functs.

~~Description~~

None

free

Takes as a parameter a node and frees the memory of

the node’s content using the function ’del’ given

as a parameter and free the node. The memory of

’next’ must not be freed.

Function name

~~Prototype~~

ft\_lstclear

void ft\_lstclear(t\_list \*\*lst, void (\*del)(void

\*));

Turn in ﬁles

Parameters

\-

lst: The address of a pointer to a node.

del: The address of the function used to delete

the content of the node.

None

free

Return value

External functs.

~~Description~~

Deletes and frees the given node and every

successor of that node, using the function ’del’

and free(3).

Finally, the pointer to the list must be set to

NULL.

13



<a name="br15"></a> 

Libft

Your very ﬁrst own library

Function name

~~Prototype~~

ft\_lstiter

void ft\_lstiter(t\_list \*lst, void (\*f)(void \*));

Turn in ﬁles

Parameters

\-

lst: The address of a pointer to a node.

f: The address of the function used to iterate on

the list.

None

None

Return value

External functs.

~~Description~~

Iterates the list ’lst’ and applies the function

’f’ on the content of each node.

Function name

~~Prototype~~

ft\_lstmap

t\_list \*ft\_lstmap(t\_list \*lst, void \*(\*f)(void \*),

void (\*del)(void \*));

Turn in ﬁles

Parameters

\-

lst: The address of a pointer to a node.

f: The address of the function used to iterate on

the list.

del: The address of the function used to delete

the content of a node if needed.

The new list.

Return value

NULL if the allocation fails.

External functs.

~~Description~~

malloc, free

Iterates the list ’lst’ and applies the function

’f’ on the content of each node. Creates a new

list resulting of the successive applications of

the function ’f’. The ’del’ function is used to

delete the content of a node if needed.

14



<a name="br16"></a> 

Chapter V

Submission and peer-evaluation

Turn in your assignment in your Git repository as usual. Only the work inside your repos-

itory will be evaluated during the defense. Don’t hesitate to double check the names of

your ﬁles to ensure they are correct.

Place all your ﬁles at the root of your repository.

15

