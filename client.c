/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 06:22:36 by ybouchra          #+#    #+#             */
/*   Updated: 2023/04/14 03:48:37 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void send_bit(int pid , int bit)
{
    if (kill(pid, 0) != 0)
        {
            perror("pid Error");
            exit(1);
        }
    if(bit == 0)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
     usleep(500);
}
    
void send_msg(int pid , char* msg)
{
    int i;

     while(*msg)
    {
        i = -1;
        while(++i < 8)
            send_bit(pid, (*msg >> i) & 1);
        msg++;
    }
}
    
int main(int ac, char **av)
{
    if (ac != 3)
    {
        write(2, "Error", 5);
        exit(1);
    }
    int pid = atoi(av[1]);
    send_msg(pid, av[2]);
}