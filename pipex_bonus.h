/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:32:37 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/22 12:50:48 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// int main(){
//     int i = 2;
//     int pipefd[2];
//     int inpid = open("infile", O_RDONLY);
//     dup2(inpid, STDIN_FILENO);
    
//     execve(); // first commnd
//     //==========================================================
//     // middle
//     // ./pipex_bonus infile cmd1 cmd2 cmd3 cmd4 outfile
//     while (i < ac - 2){
//        // if i == 2 thats mean take the file as stdinput --- i > 2 read from pipe
//         if (i == 2){
//             // use 2 pipes
//             dup2(inpid, STDIN_FILENO);
//             pipe(pipefd);
//             close(pipefd[0]);
//             dup2(pipefd[1], STDOUT_FILENO);
//             execve();
//         }
//         else
//         {
            
//         }
//     }
//     //last command
//     int outpid = open(outpid, O_WRONLY | O_CREAT | O_TRUNC, 0777);
//     dup2(outpid, STDOUT_FILENO);
//     execve() // last command
// }