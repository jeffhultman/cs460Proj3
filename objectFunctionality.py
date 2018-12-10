'''
    Author: Boaz Cogan
    Description: Clone of the Object.cpp class but for Python
'''

testing = False

def numberp(L):
    if type(L) == int or type(L) == float:
        return True
    return False

def symbolp(L):
    if type(L)==str:
        return True
    return False

def nullp(L):
    if listp(L) and (len(L)==0):
        return True
    return False


def listp(L):
    if type(L)==list:
        return True
    return False

def stringp(L):
    # What???
    return False

def listop(S,L):
    '''
    :param S: Takes a string of the Lexeme
    :param L: Takes a List to do the operations on
    :return: the result of operation S on List L
    '''
    if not listp(L):
        if testing:
            return "error"
        raise Exception("Wrong size for list operation function")
    if len(L) < 1:
        if testing:
            return "error"
        raise Exception("Wrong size for list operation function")
    Temp = L[:]
    for elem in S:
        if elem == 'd':
            Temp = cdr(Temp)
    if 'a' in S:
        return car(Temp)
    elif 'c' in S:
        return Temp
    raise Exception("Wrong name for list operation function")

def zerop(L):
    if numberp(L):
        if L==0:
            return True
        return False
    if testing:
        return "error"
    raise Exception("zerop requires a number in position 1. Received: "+str(L))

def car(L):
    if not listp(L):
        if testing:
            return "error"
        raise Exception("Car requires a list argument. Received: "+str(L))
    if len(L) == 0:
        return []
    else:
        return L[0]

def cdr(L):
    if not listp(L):
        if testing:
            return "error"
        raise Exception("Cdr requires a list argument. Received: "+str(L))
    if nullp(L):
        if testing:
            return "error"
        raise Exception("Cdr expects a tuple argument")
    if len(L) > 1:
        return L[1:]
    else:
        return []


def cons(L1,L2):
    if not listp(L2):
        if testing:
            return "error"
        raise Exception("Cons requires a list argument in position 2. Received: " + str(L2))
    if not listp(L1):
        returnValue = L2[:]
        returnValue.insert(0,L1)
        return returnValue
    return [L1[:]]+L2[:]



