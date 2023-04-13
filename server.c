/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 06:23:44 by ybouchra          #+#    #+#             */
/*   Updated: 2023/04/13 02:11:32 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int sig)
{
    static int bit;
    static int i;

    if (sig == SIGUSR2)
        i = i | (1 << bit);
    bit++;
    if (bit == 8)
    {
        write(1, &i, 1);
        bit = 0;
        i = 0;
    }
}

int main()
{
    pid_t pid;
    pid = getpid();

    printf("%d\n",pid);  
    while(1)
    {
        signal(SIGUSR1, sig_handler);
        signal(SIGUSR2, sig_handler);
        // pause();
    }
}
