<script>
    export let value = 1500;

    function handleInput(event) {
        value = event.target.value;
        dispatch('input', value);
    }

    import { createEventDispatcher } from 'svelte';
    const dispatch = createEventDispatcher();
</script>

<style>
    .slider-container {
        width: 100%;
        display: flex;
        align-items: center;
        justify-content: center;
        margin: 20px 0;
    }
    .slider {
        width: 80%;
    }
    .value-display {
        margin-left: 10px;
        font-size: 1.2em;
    }
</style>

<div class="slider-container">
    <input type="range" min="1000" max="2000" bind:value class="slider" on:input={handleInput} />
    <span class="value-display">{value}</span>
</div>
