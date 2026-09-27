'use client'

export function QuestCard({ quest }) {
  const completeQuest = async () => {
    await fetch('/api/quests/complete', {
      method: 'POST',
      body: JSON.stringify({ dailyQuestId: quest.id })
    })
  }

  return (
    <div className="rounded-xl p-4 bg-zinc-900">
      <h3>{quest.title}</h3>
      <button onClick={completeQuest}>
        Complete
      </button>
    </div>
  )
}
