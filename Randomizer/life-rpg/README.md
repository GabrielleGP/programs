# Life RPG (work in progress)

A habit tracker that turns everyday tasks into game quests. Completing daily quests earns XP, builds streaks and levels up your player stats.

## Status

Early prototype. The dashboard page, quest card and Supabase connection are in place; the quest generator, game logic, stats and login pages are still to be built.

## Planned features

- Daily quests generated from your goals
- XP bar, levels and player stats
- Streak tracking
- Login and saved progress with Supabase

## Tech

Next.js, React, TypeScript, Tailwind CSS, Supabase, Framer Motion

## Run it locally

1. Create a `.env.local` file with your Supabase project values:

   ```
   NEXT_PUBLIC_SUPABASE_URL=your-project-url
   NEXT_PUBLIC_SUPABASE_ANON_KEY=your-anon-key
   ```

2. Install and start:

   ```bash
   npm install
   npm run dev
   ```

3. Open http://localhost:3000.
