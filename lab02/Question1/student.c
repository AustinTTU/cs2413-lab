// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen
#include <stdlib.h>
#include <stdio.h>

typedef struct StringNode {
    char ch;
    struct StringNode* next;
} StringNode;

StringNode* head = NULL;

void push(char ch) {
    StringNode* temp = malloc(sizeof(StringNode));
    temp->ch = ch;
    temp->next = head;
    head = temp;
}

void pop() {
    if (head == NULL) {
        return;
    }
    StringNode* temp = head;
    head = head->next;
    free(temp);
}

char peek() {
    return head->ch;
}

void print_string() {
    StringNode* trav = head;
    while (trav != NULL) {
        printf("%c", trav->ch);
        trav = trav->next;
    }
}

static void clear_stack(void) {
    while (head != NULL) {
        pop();
    }
}

bool isValid(const char *s) {
    // TODO: Implement using a stack.
    //
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.

    if (s == NULL) // NULL case
        return false;

    clear_stack(); // reset stack

    int i = 0;
    while (s[i] != '\0') { // go through whole string (until null character)
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') { // push left bracket
            push(s[i]);
        }
        else {
            if (head == NULL) { // if nothing is pushed, ie: s = '}', then just return
                (void)s;
                return false;
            }
            char character = peek(); // get top character
            switch (s[i]) { // if char corresponds, ie: '(' = ')', then pop stack. Otherwise, return false.
                case '}':
                    if (character == '{') {
                        pop();
                    }
                    else {
                        (void)s;
                        return false;
                    }
                    break;
                case ')':
                    if (character == '(') {
                        pop();
                    }
                    else {
                        (void)s;
                        return false;
                    }
                    break;
                case ']':
                    if (character == '[') {
                        pop();
                    }
                    else {
                        (void)s;
                        return false;
                    }
            }
        }
        i++;
    }
    if (head != NULL) {
        (void)s;
        return false;
    }

    (void)s; // remove after implementing
    return true;
}