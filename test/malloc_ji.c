struct map
{
    char *m_size;
    char *m_addr;
};

/*
 * Allocate size units from the given
 * map. Return the base of the allocated
 * space.
 * Algorithm is first fit.
 */
int malloc(struct map *mp, int size)
{
	register int a;
	register struct map *bp;

	for (bp = mp; bp->m_size; bp++) {
		if (bp->m_size >= size) {
			a = bp->m_addr;
			bp->m_addr =+ size;
			if ((bp->m_size =- size) == 0)
				do {
					bp++;
					(bp-1)->m_addr = bp->m_addr;
				} while ((bp-1)->m_size = bp->m_size);
			return(a);
		}
	}
	return(0);
}