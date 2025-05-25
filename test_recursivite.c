/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_recursivite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:41:56 by syl               #+#    #+#             */
/*   Updated: 2025/05/25 14:01:47 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_rec(int a)
{
	if (a > 4)
	{
		printf("in return %i \n", a);
		return ;
	}	
	a++;
	printf("In test %i \n", a);
	test_rec(a);
}

int	test_rec2(int a)
{
	if (a > 4)
	{
		printf("in return %i \n", a);
		return (a);
	}	
	printf("In test go %i \n", a);
	a = test_rec2(a + 1);
	printf("In test %i \n", a);
	return (a);
}

int	test_rec3(int a)
{
//	a + 1;
	if (a > 4)
	{
		printf("in return %i \n", a);
		return (a - 1);
	}	
	printf("In test go %i \n", a);
	a = test_rec2(a + 1);
	printf("In test %i \n", a);
	return (a - 1);
}

void test_rec4(int a)
{
    if (a > 5)
        return;

    printf("befor rec %d \n", a);       // avant récursion
    test_rec4(a + 1);
    printf("after rec %d \n", a);       // après récursion
}

void test_rec5(int a, int b)
{
    if (a > 5)
        return;

    printf("befor rec %d - %d \n", a, b);       // avant récursion
    test_rec5(a + 1, b);
    printf("after rec %d - %d \n", a, b);       // après récursion
}
/*
befor rec 1 - 78 
befor rec 2 - 78 
befor rec 3 - 78 
befor rec 4 - 78 
befor rec 5 - 78 
after rec 5 - 78 
after rec 4 - 78 
after rec 3 - 78 
after rec 2 - 78 
after rec 1 - 78 
*/

int test_rec6(int a, int b)
{
    if (a > 5)
        return (b - 1);

    printf("before rec %d - %d\n", a, b);
    b = test_rec6(a + 1, b);
    printf("after rec %d - %d\n", a, b);
    return (b - 1);
}
/*
before rec 1 - 78
before rec 2 - 78
before rec 3 - 78
before rec 4 - 78
before rec 5 - 78
after rec 5 - 77
after rec 4 - 76
after rec 3 - 75
after rec 2 - 74
after rec 1 - 73
fin
*/

int test_rec7(int a)
{
	int b;

	b = 0;
    if (a > 5)
    {
		b = 12;
		printf("in > 5 %d - %d\n", a, b);
		return (b);
	}
    printf("before rec %d - %d\n", a, b);
    b = test_rec7(a + 1);
    printf("after rec %d - %d\n", a, b);
	b -= 1 ;
    return (b);
}


int main(void)
{
	int a;
	int res;

	a = 0;
	res = test_rec7(1);
	printf("after calc %d - %d\n", a, res);
	printf("fin\n");
	return (0);
}

