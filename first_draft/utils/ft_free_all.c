int ft_free_all(t_ls **f, t_ls **s, int is_error)
{
  t_ls *tmp

      tmp = NULL;
  if (f)
  {
    while (*f)
    {
      temp = *f;
      (*f)->value = 0;
      *f = (*f)->next;
      temp->next = NULL;
      free(temp);
    }
  }
  if (s)
  {
    while (*s)
    {
      temp = *s;
      (*s)->value = 0;
      *s = (*s)->next;
      temp->next = NULL;
      free(temp);
    }
  }
  if (is_error)
    return (exit(1));
  return (exit(0));
}