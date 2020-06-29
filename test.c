/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:34:58 by jtoty             #+#    #+#             */
/*   Updated: 2020/06/29 16:38:05 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <ctype.h>

// FT_SPLIT用
static int				count_divisions(char const *str, char target)
{
	int i;
	int blocks;

	i = 0;
	blocks = 0;
	while (str[i] != '\0')
	{
		if (str[i] != target && ((str[i + 1] == target || str[i + 1] == '\0')))
		{
			blocks++;
		}
		i++;
	}
	return (blocks);
}

void test_ft_atoi(void)
{
	printf("--------TEST: FT_ATOI-------\n");
	printf("\n1. 123456\n");
	printf("atoi   : %d\n", atoi("123456"));
	printf("ft_atoi: %d\n", ft_atoi("123456"));
	printf("\n2. 12Three45678\n");
	printf("atoi   : %d\n", atoi("12Three45678"));
	printf("ft_atoi: %d\n", ft_atoi("12Three45678"));
	printf("\n3. Hello World!\n");
	printf("atoi   : %d\n", atoi("Hello World!"));
	printf("ft_atoi: %d\n", ft_atoi("Hello World!"));
	printf("\n4. +42 BLAH!\n");
	printf("atoi   : %d\n", atoi("+42 BLAH!"));
	printf("ft_atoi: %d\n", ft_atoi("+42 BLAH!"));
	printf("\n5. -42\n");
	printf("atoi   : %d\n", atoi("-42"));
	printf("ft_atoi: %d\n", ft_atoi("-42"));
	printf("\n6. -+42\n");
	printf("atoi   : %d\n", atoi("-+42"));
	printf("ft_atoi: %d\n", ft_atoi("-+42"));
	printf("\n7. +-42\n");
	printf("atoi   : %d\n", atoi("+-42"));
	printf("ft_atoi: %d\n", ft_atoi("+-42"));
	printf("\n8.      +42\n");
	printf("atoi   : %d\n", atoi("     +42"));
	printf("ft_atoi: %d\n", ft_atoi("     +42"));
	printf("\n9. tab, space. etc 42\n");
	printf("atoi   : %d\n", atoi("\t\n\v\f\r 42"));
	printf("ft_atoi: %d\n", ft_atoi("\t\n\v\f\r 42"));
	printf("\n10. 00042\n");
	printf("atoi   : %d\n", atoi("00042"));
	printf("ft_atoi: %d\n", ft_atoi("00042"));
	printf("\n11. -2147483648(INT MIN)\n");
	printf("atoi   : %d\n", atoi("-2147483648"));
	printf("ft_atoi: %d\n", ft_atoi("-2147483648"));
	printf("\n12. 2147483647(INT MAX)\n");
	printf("atoi   : %d\n", atoi("2147483647"));
	printf("ft_atoi: %d\n", ft_atoi("2147483647"));
	printf("\n13. 9223372036854775807(LONG MAX)\n");
	printf("atoi   : %d\n", atoi("9223372036854775807"));
	printf("ft_atoi: %d\n", ft_atoi("9223372036854775807"));
	printf("\n14. -9223372036854775808(LONG MIN)\n");
	printf("atoi   : %d\n", atoi("-9223372036854775808"));
	printf("ft_atoi: %d\n", ft_atoi("-9223372036854775808"));
	printf("\n15. 99999999999999999999999999(OVERFLOW)\n");
	printf("atoi   : %d\n", atoi("99999999999999999999999999"));
	printf("ft_atoi: %d\n", ft_atoi("99999999999999999999999999"));
	printf("\n16. -99999999999999999999999999(OVERFLOW)\n");
	printf("atoi   : %d\n", atoi("-99999999999999999999999999"));
	printf("ft_atoi: %d\n", ft_atoi("-99999999999999999999999999"));
}

void test_ft_itoa(void)
{
	printf("--------TEST: FT_ITOA-------\n");
	printf("\n1. 0\n");
	printf("expt   : 0\n");
	printf("ft_itoa: %s\n", ft_itoa(0));
	printf("\n2. 111\n");
	printf("expt   : 111\n");
	printf("ft_itoa: %s\n", ft_itoa(111));
	printf("\n3. -111\n");
	printf("expt   : -111\n");
	printf("ft_itoa: %s\n", ft_itoa(-111));
	printf("\n4. 2147483647(INT MAX)\n");
	printf("expt   : 2147483647\n");
	printf("ft_itoa: %s\n", ft_itoa(INT_MAX));
	printf("\n5. -2147483648(INT MIN)\n");
	printf("expt   : -2147483647\n");
	printf("ft_itoa: %s\n", ft_itoa(INT_MIN));
}

void test_ft_split(void)
{
	printf("--------TEST: FT_SPLIT-------\n\n");
	char	**container;
	printf("---------TEST1----------\n\n");
	const char str1[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char target1 = ' ';
	printf("string = [%s]\n", str1);
	printf("target = [%c]\n", target1);
	container = ft_split(str1, target1);
	if (container)
	{
		for (int i = 0; i < count_divisions(str1, target1); i++)
		{
			printf("[%s]", container[i]);
			if (i != count_divisions(str1, target1) - 1)
			{
				printf(", ");
			}
		}
	}
	printf("\n\n");
	free(container);
	printf("---------TEST2----------\n\n");
	const char str2[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.";
	char target2 = 'i';
	printf("string = [%s]\n", str2);
	printf("target = [%c]\n", target2);
	container = ft_split(str2, target2);
	if (container)
	{
		for (int i = 0; i < count_divisions(str2, target2); i++)
		{
			printf("[%s]", container[i]);
			if (i != count_divisions(str2, target2) - 1)
			{
				printf(", ");
			}
		}
	}
	printf("\n\n");
	free(container);
	printf("---------TEST3----------\n\n");
	const char str3[] = "...........";
	char target3 = '.';
	printf("string = [%s]\n", str3);
	printf("target = [%c]\n", target3);
	container = ft_split(str3, target3);
	if (container)
	{
		for (int i = 0; i < count_divisions(str3, target3); i++)
		{
			printf("[%s]", container[i]);
			if (i != count_divisions(str1, target3) - 1)
			{
				printf(", ");
			}
		}
	}
	printf("\n\n");
	free(container);
	printf("---------TEST4----------\n\n");
	const char str4[] = "...lorem...ipsum.dolor......sit.amet,.consectetur...adipiscing.elit..Sed.non.risus..Suspendisse...";
	char target4 = '.';
	printf("string = [%s]\n", str4);
	printf("target = [%c]\n", target4);
	container = ft_split(str4, target4);
	if (container)
	{
		for (int i = 0; i < count_divisions(str4, target4); i++)
		{
			printf("[%s]", container[i]);
			if (i != count_divisions(str4, target4) - 1)
			{
				printf(", ");
			}
		}
	}
	printf("\n\n");
	free(container);
}

void test_ft_strtrim()
{
	printf("--------TEST: FT_STRTRIM-------\n\n");
	printf("---------TEST1----------\n\n");
	char *str1 = "	 #include <stdio.h>			 ";
	char *target1 = " \t";
	printf("string = [%s]\n", str1);
	printf("target = [%s]\n", target1);
	printf("\n");
	printf("expt = #include <stdio.h>\n");
	printf("test = %s\n", ft_strtrim(str1, target1));
	printf("\n");

	printf("---------TEST2----------\n\n");
	char *str2 = "         #include <stdio.h>         ";
	char *target2 = " ";
	printf("string = [%s]\n", str2);
	printf("target = [%s]\n", target2);
	printf("\n");
	printf("expt = #include <stdio.h>\n");
	printf("test = %s\n", ft_strtrim(str2, target2));
	printf("\n");

	printf("---------TEST3----------\n\n");
	char *str3 = "*;|@123***456@|;";
	char *target3 = "*;|@";
	printf("string = [%s]\n", str3);
	printf("target = [%s]\n", target3);
	printf("\n");
	printf("expt = 123***456\n");
	printf("test = %s\n", ft_strtrim(str3, target3));
	printf("\n");

	printf("---------TEST4----------\n\n");
	char *str4 = "*;|@123***456@|;";
	char *target4 = "*;|@123456";
	printf("string = [%s]\n", str4);
	printf("target = [%s]\n", target4);
	printf("\n");
	printf("expt = \n");
	printf("test = %s\n", ft_strtrim(str4, target4));
	printf("\n");

	printf("---------TEST5----------\n\n");
	char *str5 = "#*;|@123***456@|;";
	char *target5 = "*;|@";
	printf("string = [%s]\n", str5);
	printf("target = [%s]\n", target5);
	printf("\n");
	printf("expt = #*;|@123***456\n");
	printf("test = %s\n", ft_strtrim(str5, target5));
	printf("\n");

	printf("---------TEST6----------\n\n");
	char *str6 = "*;|@123***456@|;#";
	char *target6 = "*;|@";
	printf("string = [%s]\n", str6);
	printf("target = [%s]\n", target6);
	printf("\n");
	printf("expt = 123***456@|;#\n");
	printf("test = %s\n", ft_strtrim(str6, target6));
	printf("\n");
}

void test_ft_substr()
{
	printf("--------TEST: FT_SUBSTR-------\n\n");
	printf("---------TEST1----------\n\n");
	char *s1 = "0123456789";
	int start1 = 6;
	int len1 = 3;
	printf("string = %s\n", s1);
	printf("start = %d\n", start1);
	printf("len = %d\n", len1);
	printf("expt = 678\n");
	printf("test = %s\n", ft_substr(s1, start1, len1));
	printf("\n");

	printf("---------TEST2----------\n\n");
	char *s2 = "0123456789";
	int start2 = 3;
	int len2 = 100;
	printf("string = %s\n", s2);
	printf("start = %d\n", start2);
	printf("len = %d\n", len2);
	printf("expt = 3456789\n");
	printf("test = %s\n", ft_substr(s2, start2, len2));
	printf("\n");

	printf("---------TEST3----------\n\n");
	char *s3 = "0123456789";
	int start3 = 10;
	int len3 = 1;
	printf("string = %s\n", s3);
	printf("start = %d\n", start3);
	printf("len = %d\n", len3);
	printf("expt = \n");
	printf("test = %s\n", ft_substr(s3, start3, len3));
	printf("\n");
}

void test_ft_strchr()
{
	printf("--------TEST: FT_STRCHR-------\n\n");
	printf("---------TEST1----------\n\n");
	char *str1 = "abcdefghi";
	char target1 = 'c';
	printf("string = %s\n", str1);
	printf("target = %c\n", target1);
	printf("strchr    = %s\n", strchr(str1, target1));
	printf("ft_strchr = %s\n", ft_strchr(str1, target1));
	printf("\n");
	printf("---------TEST2----------\n\n");
	char *str2 = "";
	char target2 = 'c';
	printf("string = %s\n", str2);
	printf("target = %c\n", target2);
	printf("strchr    = %s\n", strchr(str2, target2));
	printf("ft_strchr = %s\n", ft_strchr(str2, target2));
	printf("\n");
	printf("---------TEST3----------\n\n");
	char *str3 = "abcd\0efg";
	char target3 = 'e';
	printf("string = abcd(ヌル文字)efg\n");
	printf("target = %c\n", target3);
	printf("strchr    = %s\n", strchr(str3, target3));
	printf("ft_strchr = %s\n", ft_strchr(str3, target3));
	printf("\n");
}

void test_ft_strrchr()
{
	printf("--------TEST: FT_STRRCHR-------\n\n");
	printf("---------TEST1----------\n\n");
	char *str1 = "abcdefaghi";
	char target1 = 'a';
	printf("string = %s\n", str1);
	printf("target = %c\n", target1);
	printf("strchr    = %s\n", strrchr(str1, target1));
	printf("ft_strchr = %s\n", ft_strrchr(str1, target1));
	printf("\n");
	printf("---------TEST2----------\n\n");
	char *str2 = "";
	char target2 = 'c';
	printf("string = %s\n", str2);
	printf("target = %c\n", target2);
	printf("strchr    = %s\n", strrchr(str2, target2));
	printf("ft_strchr = %s\n", ft_strrchr(str2, target2));
	printf("\n");
	printf("---------TEST3----------\n\n");
	char *str3 = "abcd\0efg";
	char target3 = 'c';
	printf("string = abcd(ヌル文字)efg\n");
	printf("target = %c\n", target3);
	printf("strchr    = %s\n", strrchr(str3, target3));
	printf("ft_strchr = %s\n", ft_strrchr(str3, target3));
	printf("\n");
}

void test_ft_strnstr()
{
	printf("--------TEST: FT_STRNSTR-------\n\n");
	printf("\n\nIf needle is an empty string, haystack is returned; if needle occur nowhere in haystack, NULL is returned; otherwise a pointer to the first character of the first occurrence of needle is returned.\n\n");
	const char	*largestring = "Foo Bar Baz";
	const char	*smallstring = "Bar";
	const char	*emptystring = "";
	printf("Haystack = %s\n", largestring);
	printf("Needle = %s\n", smallstring);
	printf("----strnstr-----\n");
	printf("len = 4: %s\n", strnstr(largestring, smallstring, 4));
	printf("len = 5: %s\n", strnstr(largestring, smallstring, 5));
	printf("len = 6: %s\n", strnstr(largestring, smallstring, 6));
	printf("len = 7: %s\n", strnstr(largestring, smallstring, 7));
	printf("len = 8: %s\n", strnstr(largestring, smallstring, 8));
	printf("empty: %s\n", strnstr(largestring, emptystring, 8));
	printf("----ft_strnstr-----\n");
	printf("len = 4: %s\n", ft_strnstr(largestring, smallstring, 4));
	printf("len = 5: %s\n", ft_strnstr(largestring, smallstring, 5));
	printf("len = 6: %s\n", ft_strnstr(largestring, smallstring, 6));
	printf("len = 7: %s\n", ft_strnstr(largestring, smallstring, 7));
	printf("len = 8: %s\n", ft_strnstr(largestring, smallstring, 8));
	printf("empty: %s\n", ft_strnstr(largestring, emptystring, 8));
}

void test_ft_strncmp()
{
	printf("--------TEST: FT_STRNCMP-------\n\n");
	char str[] = "ABC";
	printf("string = %s\n", str);
	printf("check up to index 2\n");
	printf("----strncmp-----\n");
	printf("ABC: ABD   = %d\n", strncmp(str, "ABD", 2));
	printf("ABC: ABC   = %d\n", strncmp(str, "ABC", 2));
    printf("ABC: AAA   = %d\n", strncmp(str, "AAA", 2));
    printf("ABC: ABCD  = %d\n", strncmp(str, "ABCD", 2));
    printf("ABC: AB    = %d\n", strncmp(str, "AB", 2));
    printf("ABC: B     = %d\n", strncmp(str, "B", 2));
    printf("ABC: A     = %d\n", strncmp(str, "A", 2));
	printf("\n");
	printf("---ft_strncmp---\n");
	printf("ABC: ABD   = %d\n", ft_strncmp(str, "ABD", 2));
	printf("ABC: ABC   = %d\n", ft_strncmp(str, "ABC", 2));
    printf("ABC: AAA   = %d\n", ft_strncmp(str, "AAA", 2));
    printf("ABC: ABCD  = %d\n", ft_strncmp(str, "ABCD", 2));
    printf("ABC: AB    = %d\n", ft_strncmp(str, "AB", 2));
    printf("ABC: B     = %d\n", ft_strncmp(str, "B", 2));
    printf("ABC: A     = %d\n", ft_strncmp(str, "A", 2));
}

void test_ft_strdup()
{
	printf("--------TEST: FT_STRDUP-------\n\n");
	printf("---------TEST1----------\n\n");
	char *str1 = "ABCDEFG";
	char *dup1;
	char *dup2;
	printf("string    = %s\n", str1);

	dup1 = strdup(str1);
	dup2 = ft_strdup(str1);
	printf("\n---After Duplicate---\n");
	printf("strdup    = %s\n", dup1);
	printf("ft_strdup = %s\n", dup2);

	printf("---------TEST2----------\n\n");
	char str2[] = "";
	char *dup3;
	char *dup4;
	printf("string    = %s\n", str2);

	dup3 = strdup(str2);
	dup4 = ft_strdup(str2);
	printf("\n---After Duplicate---\n");
	printf("strdup    = %s\n", dup3);
	printf("ft_strdup = %s\n", dup4);
}

void test_ft_strjoin()
{
	printf("--------TEST: FT_STRJOIIN-------\n\n");
	printf("---------TEST1----------\n\n");
	char *str1 = "ABC";
	char *str2 = "123";
	printf("Prefix = %s\n", str1);
	printf("Suffix = %s\n", str2);
	printf("result = %s\n", ft_strjoin(str1, str2));

	printf("---------TEST2----------\n\n");
	char *str3 = "";
	char *str4 = "";
	printf("Prefix = %s\n", str3);
	printf("Suffix = %s\n", str4);
	printf("result = %s\n", ft_strjoin(str3, str4));
}

void test_ft_strlcpy()
{
	printf("--------TEST: FT_STRLCPY-------\n\n");
	char dest1[] = "123456789";
	char src[] = "aaaaaa";
	int size = 3;
	printf("------strlcpy------\n");
	printf("dest = %s\n", dest1);
	printf("src  = %s\n", src);
	printf("size = %d\n", size);
	int original = strlcpy(dest1, src, size);
	printf("strlcpy = %s\n", dest1);
	printf("return  = %d\n", original);

	printf("------ft_strlcpy------\n");
	char dest2[] = "123456789";
	printf("dest = %s\n", dest2);
	printf("src  = %s\n", src);
	printf("size = %d\n", size);
	int ft = ft_strlcpy(dest2, src, size);
	printf("ft_strlcpy = %s\n", dest2);
	printf("return     = %d\n", ft);
}

void test_ft_strlcat()
{
	printf("--------TEST: FT_STRLCAT-------\n\n");
	printf("---strlcat---\n");
	char str1[30] = "ABC";
    char str2[] = "123";
	char *p1 = "abcd";
	int size1 = 5;
	int size2 = 4;
	int size3 = 3;

	printf("dest = %s\n", str1);
	printf("\n");
	printf("src = %s\n", str2);
	printf("size = %d\n", size1);
	printf("return = %lu\n", strlcat(str1, str2, size1));
	printf("res = %s\n", str1);
	printf("\n");
	printf("src = %s\n", p1);
	printf("size = %d\n", size2);
	printf("return = %lu\n", strlcat(str1, p1, size2));
	printf("res = %s\n", str1);
	printf("\n");
	printf("src = xyz\n");
	printf("size = %d\n", size3);
    printf("return = %lu\n", strlcat(str1, "xyz", size3));
    printf("res = %s\n", str1);
	printf("\n");

	printf("---ft_strlcat---\n");
	char str3[30] = "ABC";
	char str4[] = "123";
	char *p2 = "abcd";

	printf("dest = %s\n", str3);
	printf("src = %s\n", str4);
	printf("size = %d\n", size1);
	printf("return = %lu\n", ft_strlcat(str3, str4, size1));
	printf("res = %s\n", str3);
	printf("\n");

	printf("src = %s\n", p2);
	printf("size = %d\n", size2);
    printf("return = %lu\n", ft_strlcat(str3, p2, size2));
    printf("res = %s\n", str3);
	printf("\n");

	printf("src = xyz\n");
	printf("size = %d\n", size3);
    printf("return = %lu\n", ft_strlcat(str3, "xyz", size3));
    printf("res = %s\n", str3);
	printf("\n");
}

void test_ft_tolower(void)
{
	printf("--------TEST: FT_TOLOWER-------\n\n");
	printf("---------TEST1----------\n\n");
	char target1 = 'C';
	printf("target     = %c\n", target1);
	printf("tolower    = %d\n", tolower(target1));
	printf("ft_tolower = %d\n", ft_tolower(target1));
	printf("\n");
	printf("---------TEST2----------\n\n");
	char target2 = 'c';
	printf("target     = %c\n", target2);
	printf("tolower    = %d\n", tolower(target2));
	printf("ft_tolower = %d\n", ft_tolower(target2));
	printf("\n");
	printf("---------TEST3----------\n\n");
	char target3 = '0';
	printf("target     = %c\n", target3);
	printf("tolower    = %d\n", tolower(target3));
	printf("ft_tolower = %d\n", ft_tolower(target3));
	printf("\n");
}

void test_ft_toupper(void)
{
	printf("--------TEST: FT_TOUPPER-------\n\n");
	printf("---------TEST1----------\n\n");
	char target1 = 'C';
	printf("target     = %c\n", target1);
	printf("toupper    = %d\n", toupper(target1));
	printf("ft_toupper = %d\n", ft_toupper(target1));
	printf("\n");
	printf("---------TEST2----------\n\n");
	char target2 = 'c';
	printf("target     = %c\n", target2);
	printf("toupper    = %d\n", toupper(target2));
	printf("ft_toupper = %d\n", ft_toupper(target2));
	printf("\n");
	printf("---------TEST3----------\n\n");
	char target3 = '0';
	printf("target     = %c\n", target3);
	printf("toupper    = %d\n", toupper(target3));
	printf("ft_toupper = %d\n", ft_toupper(target3));
	printf("\n");
}

void test_ft_isalpha()
{
	printf("--------TEST: FT_ISALPHA-------\n\n");
	printf("---------TEST1----------\n\n");
	char target1 = 'C';
	printf("target     = %c\n", target1);
	printf("isalpha    = %d\n", isalpha(target1));
	printf("ft_isalpha = %d\n", ft_isalpha(target1));
	printf("\n");
	printf("---------TEST2----------\n\n");
	char target2 = '1';
	printf("target     = %c\n", target2);
	printf("isalpha    = %d\n", isalpha(target2));
	printf("ft_isalpha = %d\n", ft_isalpha(target2));
	printf("\n");
	printf("---------TEST3----------\n\n");
	char target3 = '\n';
	printf("target     = %c\n", target3);
	printf("isalpha    = %d\n", isalpha(target3));
	printf("ft_isalpha = %d\n", ft_isalpha(target3));
	printf("\n");
}

void test_ft_memset()
{
	printf("--------TEST: FT_MEMSET-------\n\n");
	char str1[] = "0123456789";
	char str2[] = "0123456789";
	int c = 'a';
	int len = 5;
	printf("string = %s\n", str1);
	printf("c = %c, len = %d\n", c, len);
	memset(str1, c, len);
	printf("memset    = %s\n", str1);
	ft_memset(str2, c, len);
	printf("ft_memset = %s\n", str2);
	printf("\n");
}

void test_ft_bzero()
{
	printf("--------TEST: FT_BZERO-------\n\n");
	char str1[] = "0123456789";
	char str2[] = "0123456789";
	int len = 5;
	printf("string = %s\n", str1);
	printf("len = %d\n", len);
	bzero(str1, len);
	printf("\n------bzero-------\n");
	for (int i = 0; i < len; i++)
	{
		if (str1[i] == '\0')
		{
			printf("null ");
		}
	}
	printf("\n");
	ft_bzero(str2, len);
	printf("\n------ft_bzero-------\n");
	for (int i = 0; i < len; i++)
	{
		if (str2[i] == '\0')
		{
			printf("null ");
		}
	}
	printf("\n");
}

void test_ft_memcpy()
{
	printf("--------TEST: FT_MEMCPY-------\n\n");
	char dest1[128] = {1,1,1,1,1,1,1};
	char src1[] = "ab\0cde";
	int n = 5;
	printf("-----memcpy------\n\n");
	printf("コピー前\n");
	printf("dest: ");
	for (int i = 0; i < 7; i++)
	{
		printf("%#x ",dest1[i]);
	}
	printf("\n");
	printf("src: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%#x ",src1[i]);
	}
	printf("\n");
	printf("n = %d\n", n);
	memcpy(dest1, src1, n);
	printf("コピー後\n");
	for (int i = 0; i < 7; i++)
	{
		printf("%#x ",dest1[i]);
	}
	printf("\n\n");

	char dest2[128] = {1,1,1,1,1,1,1};
	char src2[] = "ab\0cde";
	printf("-----ft_memcpy------\n\n");
	printf("コピー前\n");
	printf("dest: ");
	for (int i = 0; i < 7; i++)
	{
		printf("%#x ",dest2[i]);
	}
	printf("\n");
	printf("src: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%#x ",src2[i]);
	}
	printf("\n");
	printf("n = %d\n", n);
	ft_memcpy(dest2, src2, n);
	printf("コピー後\n");
	for (int i = 0; i < 7; i++)
	{
		printf("%#x ",dest2[i]);
	}
	printf("\n\n");
}

void test_ft_memcmp()
{
	printf("--------TEST: FT_MEMCMP-------\n\n");
	char str1[] = "\0abc\0de";
	char str2[] = "\0abc\0de";
	char str3[] = "\0abcdef";
	int n = 7;
	printf("str1: ");
	for (int i = 0; i < 7; i++)
	{
		if (str1[i] == '\0')
		{
			printf("0");
		}
		else
		{
			printf("%c", str1[i]);
		}
	}
	printf("\n");
	printf("str2: ");
	for (int i = 0; i < 7; i++)
	{
		if (str2[i] == '\0')
		{
			printf("0");
		}
		else
		{
			printf("%c", str2[i]);
		}
	}
	printf("\n");
	printf("str3: ");
	for (int i = 0; i < 7; i++)
	{
		if (str3[i] == '\0')
		{
			printf("0");
		}
		else
		{
			printf("%c", str3[i]);
		}
	}
	printf("\n");
	printf("n = %d\n", n);
	printf("-----memcmp-----\n");
	printf("str1 - str2 = %d\n", memcmp(str1, str2, n));
	printf("str1 - str3 = %d\n", memcmp(str1, str3, n));
	printf("\n");
	printf("-----ft_memcmp-----\n");
	printf("str1 - str2 = %d\n", ft_memcmp(str1, str2, n));
	printf("str1 - str3 = %d\n", ft_memcmp(str1, str3, n));
	printf("\n");
}

void test_ft_memchr()
{
	printf("--------TEST: FT_MEMCHR-------\n\n");
	char str[] = "abcdef\0ghij";
	char *p1;
	char *p2;
	printf("string = ");
	for (int i = 0; i < 11; i++)
	{
		if (str[i] == '\0')
		{
			printf("0");
		}
		else
		{
			printf("%c", str[i]);
		}
	}
	printf("\n");
	int c = 'h';
	int n = 12;
	printf("c = %c\n", c);
	printf("n = %d\n", n);
	printf("-----memchr-----\n");
	printf("memchr    = %s\n", memchr(str, c, n));
	printf("-----ft_memchr-----\n");
	printf("ft_memchr = %s\n", ft_memchr(str, c, n));
}

void test_ft_memccpy()
{
	printf("--------TEST: FT_MEMCCPY-------\n\n");
	char dest1[] = "0123456789";
	char dest2[] = "0123456789";
	char src1[] = "abcdefghi";
	int c = 'c';
	int n = 5;
	printf("dest = %s\n", dest1);
	printf("src  = ");
	for (int i = 0; i < 6; i++)
	{
		if (src1[i] == '\0')
		{
			printf("0");
		}
		else
		{
			printf("%c", src1[i]);
		}
	}
	printf("\n");
	printf("c = %d\n", c);
	printf("n = %d\n", n);
	printf("memccpy    = %s\n", memccpy(dest1, src1, c, n));
	printf("dest = %s\n", dest1);
	printf("ft_memccpy = %s\n", ft_memccpy(dest2, src1, c, n));
	printf("dest = %s\n", dest2);
}

void test_ft_memmove()
{
	printf("--------TEST: FT_MEMMOVE-------\n\n");
	char first[] = "stackoverflow";
	char second[] = "stackoverflow";
	int start = 5;
	int n = 7;
	printf("-----memmove---\n");
	printf("Before：%s\n",first);
	printf("dest = %s, src = %s, n = %d\n", first + start, first, n);
	memmove(first + 5, first, 7);
	printf("After ：%s\n", first);

	printf("-----ft_memmove-----\n");
	printf("Before：%s\n",second);
	printf("dest = %s, src = %s, n = %d\n", second + start, second, n);
	ft_memmove(second+5, second, 7);
	printf("After ：%s\n", second);
}

void test_ft_putnbr()
{
	printf("--------TEST: FT_PUTNBR-------\n\n");
	int test1 = 12345;
	int test2 = -12345;
	int test3 = INT_MAX;
	int test4 = INT_MIN;

	printf("---------TEST1----------\n\n");
	printf("Test1: %d\n", test1);
	ft_putnbr_fd(test1, 1);
	printf("\n");
	printf("---------TEST2----------\n\n");
	printf("Test2: %d\n", test2);
	ft_putnbr_fd(test2, 1);
	printf("\n");
	printf("---------TEST3----------\n\n");
	printf("Test3: %d\n", test3);
	ft_putnbr_fd(test3, 1);
	printf("\n");
	printf("---------TEST4----------\n\n");
	printf("Test4: %d\n", test4);
	ft_putnbr_fd(test4, 1);
	printf("\n");
}

char add_5_words(unsigned int i, char c)
{
	if (i < 5)
	{
		return (c);
	}
	return (0);
}

void test_ft_strmapi()
{
	printf("--------TEST: FT_STRMAPI-------\n\n");
	char *str = "0123456789";
	char *result;
	char (*func)(unsigned int, char);

	printf("s = %s\n", str);
	printf("f = add_5_words(unsigned int i, char c)\n");
	func = add_5_words;
	result = ft_strmapi(str, func);
	printf("result = %s\n", result);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		// !MEMORY
		test_ft_memcpy();
		test_ft_memset();
		test_ft_bzero();
		test_ft_memmove();
		test_ft_memcmp();
		test_ft_memchr();
		test_ft_memccpy();

		// !STRING
		test_ft_isalpha();
		test_ft_toupper();
		test_ft_tolower();
		test_ft_strchr();
		test_ft_strrchr();
		test_ft_strlcat();
		test_ft_atoi();
		test_ft_strnstr();
		test_ft_strncmp();
		test_ft_strlcpy();

		// !MALLOC
		test_ft_strdup();

		//! 自作関数
		test_ft_substr();
		test_ft_strjoin();
		test_ft_strtrim();
		test_ft_split();
		test_ft_itoa();
		test_ft_putnbr();
		test_ft_strmapi();
	}
	if (argc > 1)
	{
		// !MEMORY
		if (strcmp(argv[1], "memcpy") == 0)
			test_ft_memcpy();
		if (strcmp(argv[1], "memset") == 0)
			test_ft_memset();
		if (strcmp(argv[1], "bzero") == 0)
			test_ft_bzero();
		if (strcmp(argv[1], "memmove") == 0)
			test_ft_memmove();
		if (strcmp(argv[1], "memcmp") == 0)
			test_ft_memcmp();
		if (strcmp(argv[1], "memchr") == 0)
			test_ft_memchr();
		if (strcmp(argv[1], "memccpy") == 0)
			test_ft_memccpy();

		// !STRING
		if (strcmp(argv[1], "isalpha") == 0)
			test_ft_isalpha();
		if (strcmp(argv[1], "toupper") == 0)
			test_ft_toupper();
		if (strcmp(argv[1], "tolower") == 0)
			test_ft_tolower();
		if (strcmp(argv[1], "strchr") == 0)
			test_ft_strchr();
		if (strcmp(argv[1], "strrchr") == 0)
			test_ft_strrchr();
		if (strcmp(argv[1], "strlcat") == 0)
			test_ft_strlcat();
		if (strcmp(argv[1], "atoi") == 0)
			test_ft_atoi();
		if (strcmp(argv[1], "strnstr") == 0)
			test_ft_strnstr();
		if (strcmp(argv[1], "strncmp") == 0)
			test_ft_strncmp();
		if (strcmp(argv[1], "strlcpy") == 0)
			test_ft_strlcpy();

		// !MALLOC
		if (strcmp(argv[1], "strdup") == 0)
			test_ft_strdup();
		if (strcmp(argv[1], "itoa") == 0)
			test_ft_itoa();
		if (strcmp(argv[1], "split") == 0)
			test_ft_split();
		if (strcmp(argv[1], "strtrim") == 0)
			test_ft_strtrim();
		if (strcmp(argv[1], "substr") == 0)
			test_ft_substr();
		if (strcmp(argv[1], "strjoin") == 0)
			test_ft_strjoin();
		if (strcmp(argv[1], "putnbr") == 0)
			test_ft_putnbr();
		if (strcmp(argv[1], "strmapi") == 0)
			test_ft_strmapi();
	}
	return (0);
}
