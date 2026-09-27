import { supabase } from '@/lib/supabaseClient'

export default async function Dashboard() {
  const { data: stats } = await supabase
    .from('player_stats')
    .select('*')
    .single()

  const { data: quests } = await supabase
    .from('daily_quests')
    .select('id, quests(*)')
    .eq('completed', false)

  return (
    <main className="p-6 space-y-6">
      <HeaderPlayerInfo />
      <StatsGrid stats={stats} />
      <DailyQuestList quests={quests} />
    </main>
  )
}
