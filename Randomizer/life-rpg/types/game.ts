export type PlayerStats = {
  health: number
  focus: number
  wealth: number
  knowledge: number
  freedom: number
  mental: number
}

export type Quest = {
  id: string
  title: string
  xp_reward: number
  stat_rewards: Partial<PlayerStats>
  difficulty: 'easy' | 'normal' | 'hard'
}
