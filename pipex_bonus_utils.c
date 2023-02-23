/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:31:56 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/23 08:21:29 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    middle_child(char *cmd, char **envp, int ac, char **av){
    int count;
    int fd[2];
    int fd2;
    int pid;

    count = 2;
    fd2 = 0;
    while (++count < ac - 2){
        pipe(fd);
        pid = fork();
        if(pid == 0){
            dup2(fd2, 0);
            close(fd2)
            dup2(fd[1], 1);
            close(fd[1]); //fd[0]
             execve()
            
        }
        else
        {
            waitpid(pid, NULL, 0);
            close(fd[1]);
            fd2 = fd[0];
        }
    }
}

void	child1(char *infile, char *cmd1, char **envp, int fd[])
{
	char	**args;
	char	*cmd_path;
	int		fpid;
	char	**paths;

	paths = get_paths(envp);
	args = ft_split(cmd1, ' ');
	if (slash(args) == 3)
		cmd_path = args[0];
	else
		cmd_path = check_command(cmd1, paths);
	close(fd[0]);
	fpid = open(infile, O_RDONLY);
	if (fpid == -1)
	{
		perror("open failed");
		exit(EXIT_FAILURE);
	}
	fail_cheack(dup2(fpid, STDIN_FILENO), "dup2 failed");
	close(fpid);
	fail_cheack(dup2(fd[1], STDOUT_FILENO), "dup2 failed");
	close(fd[1]);
	fail_cheack(execve(cmd_path, args, envp), "execve failed");
}